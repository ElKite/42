package vtarreau.ft_hangouts.activities;

import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AlertDialog;
import android.view.View;
import android.view.Menu;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.adapter.ContactListAdapter;
import vtarreau.ft_hangouts.database.DataBaseAPI;

public class MainActivity extends MyActivity {

    DataBaseAPI db;
    ContactListAdapter adapter;
    ArrayList<Contact> contacts;
    ListView contactList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {


        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setToolbar();

        db = new DataBaseAPI(this);
        contactList = (ListView) findViewById(R.id.contactList);


        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getBaseContext(), AddContactActivity.class);
                startActivity(intent);
            }
        });

        contactList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Intent intent = new Intent(MainActivity.this, ContactActivity.class);
                intent.putExtra(AddContactActivity.ID_TO_EDIT, String.valueOf(contacts.get(i).getId()));
                startActivity(intent);
            }
        });

        contactList.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> adapterView, View view, int i, long l) {
                final AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
                ListView listOptions = new ListView(MainActivity.this);
                final int contactposition = i;
                String[] options = new String[] {getResources().getString(R.string.edit_contact), getResources().getString(R.string.delete_contact)};
                ArrayAdapter<String> listAdapter = new ArrayAdapter<String>
                        (MainActivity.this, android.R.layout.simple_list_item_1, android.R.id.text1, options);
                listOptions.setAdapter(listAdapter);
                builder.setView(listOptions);
                final Dialog dialog = builder.create();

                listOptions.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                    @Override
                    public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                        if (i == 0) {
                            Intent intent = new Intent(MainActivity.this, AddContactActivity.class);
                            dialog.dismiss();
                            intent.putExtra(AddContactActivity.ID_TO_EDIT, String.valueOf(contacts.get(contactposition).getId()));
                            startActivity(intent);
                        } else if (i == 1) {
                            db.openForWrite();
                            db.removeContact(contacts.get(contactposition).getId());
                            db.close();
                            dialog.dismiss();
                            getAllContacts();
                            displayContacts();
                        }
                    }
                });
                dialog.show();
                return true;
            }
        });
    }

    public void displayContacts() {
        if (contacts != null) {
            if (adapter != null) {
                adapter.clear();
                if (contacts != null) {
                    adapter.addAll(contacts);
                    adapter.notifyDataSetChanged();
                }
            }
            else {
                adapter = new ContactListAdapter(this, contacts);
                contactList.setAdapter(adapter);
            }
        } else {
            if (adapter == null)
                Toast.makeText(this, "Pas de contact...", Toast.LENGTH_LONG).show();
            else
                adapter.clear();
        }
    }

    public void getAllContacts() {
        db.openForRead();
        contacts = db.getAllContact();
        db.close();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    protected void onResume() {
        getAllContacts();
        displayContacts();
        super.onResume();
    }
}

package vtarreau.ft_hangouts.activities;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ListView;
import android.widget.Toast;

import java.util.ArrayList;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.adapter.ContactListAdapter;
import vtarreau.ft_hangouts.database.DataBaseAPI;

public class MainActivity extends AppCompatActivity {

    DataBaseAPI db;
    ContactListAdapter adapter;
    ArrayList<Contact> contacts;
    ListView contactList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });
        db = new DataBaseAPI(this);
        contactList = (ListView) findViewById(R.id.contactList);

        getAllContacts();
        displayContacts();
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
        } else
            Toast.makeText(this, "Pas de contact...", Toast.LENGTH_LONG).show();
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
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}

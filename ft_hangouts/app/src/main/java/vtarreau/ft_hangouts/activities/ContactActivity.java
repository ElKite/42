package vtarreau.ft_hangouts.activities;

import android.app.ActionBar;
import android.app.Dialog;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.database.DataBaseAPI;

/**
 * Created by Vincent on 02/12/2016.
 */

public class ContactActivity extends MyActivity {
    final public static String ID_TO_EDIT = "ID_TO_EDIT";
    final public static String CONTACT_NUMBER = "CONTACT_NUMBER";

    TextView Firstname;
    TextView Lastname;
    TextView Mobile;
    TextView Phone;
    TextView Address;
    TextView Email;

    ImageButton call;
    ImageButton sms;
    ImageButton edit;
    ImageButton mail;

    Contact contact;
    DataBaseAPI db;
    int id;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contact);
        setToolbar();

        Firstname = (TextView) findViewById(R.id.contact_firstname);
        Lastname = (TextView) findViewById(R.id.contact_lastname);
        Mobile = (TextView) findViewById(R.id.contact_mobile);
        Phone = (TextView) findViewById(R.id.contact_phone);
        Address = (TextView) findViewById(R.id.contact_address);
        Email = (TextView) findViewById(R.id.contact_email);

        call = (ImageButton) findViewById(R.id.call);
        sms = (ImageButton) findViewById(R.id.sms);
        edit = (ImageButton) findViewById(R.id.edit);
        mail = (ImageButton) findViewById(R.id.email);


        db = new DataBaseAPI(this);

        getIntent().getStringExtra(ID_TO_EDIT);
        id = Integer.parseInt(getIntent().getStringExtra(ID_TO_EDIT));

        refreshdata();

        edit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(ContactActivity.this, AddContactActivity.class);
                intent.putExtra(AddContactActivity.ID_TO_EDIT, String.valueOf(id));
                startActivityForResult(intent, RESULT_CANCELED);
            }
        });

        sms.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(ContactActivity.this, SmsActivity.class);
                intent.putExtra(CONTACT_NUMBER, contact.getMobile());
                startActivity(intent);
            }
        });
        mail.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(Intent.ACTION_SEND);
                i.setType("message/rfc822");
                i.putExtra(Intent.EXTRA_EMAIL  , new String[]{contact.getMail()});
                i.putExtra(Intent.EXTRA_SUBJECT, "");
                i.putExtra(Intent.EXTRA_TEXT   , "");
                try {
                    startActivity(Intent.createChooser(i, "Send mail..."));
                } catch (android.content.ActivityNotFoundException ex) {
                    Toast.makeText(ContactActivity.this, "There are no email clients installed.", Toast.LENGTH_SHORT).show();
                }
            }
        });
        call.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (contact.getPhone().length() > 0 && contact.getMobile().length() > 0) {
                    final AlertDialog.Builder builder = new AlertDialog.Builder(ContactActivity.this);
                    ListView listOptions = new ListView(ContactActivity.this);
                    String[] options = new String[]{"Mobile", "Phone"};
                    ArrayAdapter<String> listAdapter = new ArrayAdapter<String>
                            (ContactActivity.this, android.R.layout.simple_list_item_1, android.R.id.text1, options);
                    listOptions.setAdapter(listAdapter);
                    builder.setView(listOptions);
                    final Dialog dialog = builder.create();

                    listOptions.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                        @Override
                        public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                            if (i == 0) {
                                Intent intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:" + contact.getMobile()));
                                startActivity(intent);
                            } else if (i == 1) {
                                Intent intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:" + contact.getPhone()));
                                startActivity(intent);
                            }
                        }
                    });
                    dialog.show();

                } else if (contact.getPhone().length() > 0 && contact.getMobile().length() == 0) {
                    Intent intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:" + contact.getPhone()));
                    startActivity(intent);
                } else if (contact.getMobile().length() > 0 && contact.getPhone().length() == 0) {
                    Intent intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:" + contact.getMobile()));
                    startActivity(intent);
                }
            }
        });
    }

    public void refreshdata() {
        db.openForRead();
        contact = db.getAContactID(id);
        db.close();

        Firstname.setText(contact.getFirstname().length() == 0 ? "" : contact.getFirstname());
        Lastname.setText(contact.getLastname().length() == 0 ? "" : contact.getLastname());
        Mobile.setText(contact.getMobile().length() == 0 ? "" : contact.getMobile());
        Phone.setText(contact.getPhone().length() == 0 ? "" : contact.getPhone());
        Address.setText(contact.getAddress().length() == 0 ? "" : contact.getAddress());
        Email.setText(contact.getMail().length() == 0 ? "" : contact.getMail());
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent intent) {
        super.onActivityResult(requestCode, resultCode, intent);

        if (requestCode == RESULT_CANCELED) {
            refreshdata();
        }
    }
}

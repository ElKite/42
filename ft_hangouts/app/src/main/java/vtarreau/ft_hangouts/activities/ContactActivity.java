package vtarreau.ft_hangouts.activities;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.database.DataBaseAPI;

/**
 * Created by Vincent on 02/12/2016.
 */

public class ContactActivity extends AppCompatActivity {
    final public static String ID_TO_EDIT = "ID_TO_EDIT";

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
    DataBaseAPI db;
    int id;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contact);

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


        edit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(ContactActivity.this, AddContactActivity.class);
                intent.putExtra(AddContactActivity.ID_TO_EDIT, String.valueOf(id));
                startActivityForResult(intent, RESULT_CANCELED);
            }
        });
        refreshdata();
    }

    public void refreshdata() {
        Contact contact;

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
            refreshdata(); // your "refresh" code
        }
    }
}

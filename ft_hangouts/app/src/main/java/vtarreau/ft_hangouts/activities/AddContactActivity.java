package vtarreau.ft_hangouts.activities;

import android.os.Bundle;

import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.database.DataBaseAPI;

/**
 * Created by Vincent on 29/11/2016.
 */

public class AddContactActivity extends AppCompatActivity {

    final public static String ID_TO_EDIT = "ID_TO_EDIT";

    EditText Firstname;
    EditText Lastname;
    EditText Mobile;
    EditText Phone;
    EditText Address;
    EditText Email;
    Button Save;
    DataBaseAPI db;
    int id;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_addcontact);

        Firstname = (EditText) findViewById(R.id.firstNameAdd);
        Lastname = (EditText) findViewById(R.id.LastNameAdd);
        Mobile = (EditText) findViewById(R.id.MobileAdd);
        Phone = (EditText) findViewById(R.id.PhoneAdd);
        Address = (EditText) findViewById(R.id.AddressAdd);
        Email = (EditText) findViewById(R.id.emailAdd);
        Save = (Button) findViewById(R.id.saveContact);

        db = new DataBaseAPI(this);

        id = getIntent().getStringExtra(ID_TO_EDIT);
        if (id == null) {
            createContact();
        } else
            editContact();
    }

    private void createContact() {
        Save.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (Firstname.getText().equals(""))
                    Toast.makeText(getApplicationContext(), "You need at least a first name to create a contact", Toast.LENGTH_LONG).show();
                else {
                    Contact contact = new Contact(
                            Firstname.getText().toString(), Lastname.getText().toString(),
                            Mobile.getText().toString(), Phone.getText().toString(),
                            Address.getText().toString(), Email.getText().toString()
                    );
                    db.openForWrite();
                    db.insertContact(contact);
                    db.close();
                }
            }
        });
    }

    private void editContact() {
        db.openForRead();
        db.getAContactID(id)
    }
}

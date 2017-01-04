package vtarreau.ft_hangouts.activities;

import android.content.ContentResolver;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ListView;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.adapter.SmsListAdapter;
import vtarreau.ft_hangouts.database.DataBaseAPI;

/**
 * Created by vtarreau on 12/6/16.
 */


public class SmsActivity extends AppCompatActivity {

    ImageButton send_sms;
    EditText sms_content;
    SmsListAdapter adapter;
    ListView sms_list;

    ArrayList<String> inbox;
    ArrayList<String> sent;
    String ContactPhoneNumber;
    String ContactName;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sms);

        send_sms = (ImageButton) findViewById(R.id.send_sms_button);
        sms_content = (EditText) findViewById(R.id.write_sms);
        sms_list = (ListView) findViewById(R.id.sms_list);

        inbox = new ArrayList<>();
        sent = new ArrayList<>();

        ContactPhoneNumber = getIntent().getStringExtra(ContactActivity.CONTACT_NUMBER).substring(1);
        ContactPhoneNumber = "+33" + ContactPhoneNumber;

        send_sms.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //SEND SMS
            }
        });
        refreshdata();
    }

    private void refreshdata() {

        retrieveInbox();
        retrieveSentSms();

        if (adapter == null) {
            adapter = new SmsListAdapter(SmsActivity.this, sent, inbox, ContactName);
            sms_list.setAdapter(adapter);
        }
        //fetch sent + inbox, sort by date
    }

    private void retrieveInbox() {
        Uri mSmsinboxQueryUri = Uri.parse("content://sms/inbox");
        Cursor c = getContentResolver().query(mSmsinboxQueryUri,new String[] { "_id", "thread_id", "address", "person", "date","body", "type" }, null, null, "normalized_date desc");
        startManagingCursor(c);
            if (c.moveToFirst()) {
                for (int i = 0; i < c.getCount(); i++) {
                    String address = c.getString(c.getColumnIndex("address"));
                    if (address.equalsIgnoreCase(ContactPhoneNumber))
                        inbox.add(c.getString(c.getColumnIndex("body")).toString());
                    c.moveToNext();
                }
            }
            c.close();
    }

    private void retrieveSentSms() {
        Uri mSmsinboxQueryUri = Uri.parse("content://sms/sent");
        Cursor c = getContentResolver().query(mSmsinboxQueryUri,new String[] { "_id", "thread_id", "address", "person", "date","body", "type" }, "address = '" + ContactPhoneNumber + "'", null, "normalized_date desc");
        startManagingCursor(c);
            if (c.moveToFirst()) {
                for (int i = 0; i < c.getCount(); i++) {
                    inbox.add(c.getString(c.getColumnIndex("body")).toString());
                    c.moveToNext();
                }
            }
            c.close();
    }

}

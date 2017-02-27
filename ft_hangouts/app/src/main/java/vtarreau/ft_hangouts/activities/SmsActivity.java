package vtarreau.ft_hangouts.activities;

import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.database.Cursor;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.telephony.SmsManager;
import android.telephony.SmsMessage;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.Toast;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.SMSBroadcastReceiver;
import vtarreau.ft_hangouts.adapter.SmsListAdapter;
import vtarreau.ft_hangouts.database.DataBaseAPI;

/**
 * Created by vtarreau on 12/6/16.
 */


public class SmsActivity extends MyActivity {

    ImageButton send_sms;
    EditText sms_content;
    SmsListAdapter adapter;
    ListView sms_list;

    ArrayList<String> inbox;
    ArrayList<String> smsFrom;
    String ContactPhoneNumber;

    String me;

    private static SmsActivity inst;

    public static SmsActivity instance() {
        return inst;
    }

    @Override
    public void onStart() {
        super.onStart();
        inst = this;
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sms);
        setToolbar();

        send_sms = (ImageButton) findViewById(R.id.send_sms_button);
        sms_content = (EditText) findViewById(R.id.write_sms);
        sms_list = (ListView) findViewById(R.id.sms_list);
        ContactPhoneNumber = getIntent().getStringExtra(ContactActivity.CONTACT_NUMBER).substring(1);
        ContactPhoneNumber = "+33" + ContactPhoneNumber;

        me = getResources().getString(R.string.me);

        inbox = new ArrayList<>();
        smsFrom = new ArrayList<>();

        send_sms.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                SmsManager smsManager = SmsManager.getDefault();
                String number = ContactPhoneNumber;
                String msg = sms_content.getText().toString();
                smsManager.sendTextMessage(number, null, msg, null, null);
                sms_content.setText("");
                addSms(msg, me);
            }
        });
        retrieveInbox();
        refreshdata();
    }

    public void addSms(String content, String number) {
        if (number.equals(ContactPhoneNumber) || number.equals(getResources().getString(R.string.me))) {
            inbox.add(content);
            smsFrom.add(number);
            refreshdata();
        }
    }

    private void refreshdata() {
        if (adapter == null) {
            adapter = new SmsListAdapter(SmsActivity.this, inbox, smsFrom);
            sms_list.setAdapter(adapter);
            sms_list.setSelection(sms_list.getCount() -1);
        } else {
            adapter.notifyDataSetChanged();
            sms_list.setSelection(sms_list.getCount() -1);
        }
    }

    private void retrieveInbox() {
        Uri mSmsinboxQueryUri = Uri.parse("content://sms/");
        Cursor c = getContentResolver().query(mSmsinboxQueryUri,new String[] { "_id", "thread_id", "address", "person", "date","body", "type" }, null, null, null);
        startManagingCursor(c);
            if (c.moveToFirst()) {
                for (int i = 0; i < c.getCount(); i++) {
                    String address = c.getString(c.getColumnIndex("address"));
                    //Log.e(address, c.getString(c.getColumnIndex("person")) + " | " + c.getString(c.getColumnIndex("type")) + " | " + c.getString(c.getColumnIndex("_id")));
                    if (address.equalsIgnoreCase(ContactPhoneNumber)) {
                        inbox.add(c.getString(c.getColumnIndex("body")).toString());
                        if (c.getString(c.getColumnIndex("type")).equals("2")) {
                            smsFrom.add(me);
                        }
                        else
                            smsFrom.add(address);

                    }
                    c.moveToNext();
                }
            }
            c.close();

        Collections.reverse(inbox);
        Collections.reverse(smsFrom);
    }
}

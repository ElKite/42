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

import java.util.ArrayList;

import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.adapter.SmsListAdapter;

/**
 * Created by vtarreau on 12/6/16.
 */


public class SmsActivity extends AppCompatActivity {

    ImageButton send_sms;
    EditText sms_content;
    SmsListAdapter adapter;
    ListView sms_list;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sms);

        send_sms = (ImageButton) findViewById(R.id.send_sms_button);
        sms_content = (EditText) findViewById(R.id.write_sms);
        sms_list = (ListView) findViewById(R.id.sms_list);

        send_sms.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        refreshdata();
    }

    private void refreshdata() {

        ArrayList<String> msg = new ArrayList<String>();

       /*Cursor cursor = getContentResolver().query(Uri.parse("content://sms/inbox"), null, null, null, null);

        if (cursor.moveToFirst()) { // must check the result to prevent exception
            do {
                String msgData = "";
                for(int idx=0;idx<cursor.getColumnCount();idx++)
                {
                    msgData += " " + cursor.getColumnName(idx) + ":" + cursor.getString(idx);
                }
                msg.add(msgData);
            } while (cursor.moveToNext());
        } else {
            // empty box, no SMS
        }

        if (adapter == null) {
            adapter = new SmsListAdapter(this, "sender");
            adapter.addAll(msg);
        }*/

        Uri uri = Uri.parse("content://sms/conversations");
        Cursor c= getContentResolver().query(uri, null,"address = '+33688967650'", null, null,null);


        if(c.moveToFirst())
        {
            for(int i=0;i<c.getCount();i++){
                msg.add(c.getString(c.getColumnIndexOrThrow("body")).toString());
                Log.e("tEST", c.getString(c.getColumnIndexOrThrow("address")).toString());
                c.moveToNext();
            }
        }
        c.close();
        if (adapter == null) {
            adapter = new SmsListAdapter(SmsActivity.this, msg);
            sms_list.setAdapter(adapter);
        }
        //fetch sent + inbox, sort by date
    }

}

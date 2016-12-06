package vtarreau.ft_hangouts.activities;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.ImageButton;

import vtarreau.ft_hangouts.R;
import vtarreau.ft_hangouts.adapter.SmsListAdapter;

/**
 * Created by vtarreau on 12/6/16.
 */


public class SmsActivity extends AppCompatActivity {

    ImageButton send_sms;
    EditText sms_content;
    SmsListAdapter adapter;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sms);

        send_sms = (ImageButton) findViewById(R.id.send_sms_button);
        sms_content = (EditText) findViewById(R.id.write_sms);

        send_sms.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
        refreshdata();
    }

    private void refreshdata() {
        if (adapter == null) {
            adapter = new SmsListAdapter(this);
        }
    }
}

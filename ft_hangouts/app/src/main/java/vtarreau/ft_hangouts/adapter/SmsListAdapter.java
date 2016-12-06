package vtarreau.ft_hangouts.adapter;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;


import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;

/**
 * Created by vtarreau on 12/6/16.
 */

public class SmsListAdapter extends ArrayAdapter<Contact> {
    private static class ViewHolder {
        private TextView sms_text;
        private TextView sms_sender;
    }

    public SmsListAdapter(Context context) {
        super(context, R.layout.content_main);
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        SmsListAdapter.ViewHolder viewHolder = null;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.getContext())
                    .inflate(R.layout.content_main, parent, false);
            viewHolder = new SmsListAdapter.ViewHolder();
            viewHolder.sms_text = (TextView) convertView.findViewById(R.id.firstname);
            viewHolder.sms_sender = (TextView) convertView.findViewById(R.id.lastname);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (SmsListAdapter.ViewHolder) convertView.getTag();
        }
        //position pair background gris sinon blanc
        viewHolder.sms_text.setText("TEXT");
        viewHolder.sms_sender.setText("SENDER");
        return convertView;
    }
}

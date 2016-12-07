package vtarreau.ft_hangouts.adapter;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;


import java.util.ArrayList;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;

/**
 * Created by vtarreau on 12/6/16.
 */

public class SmsListAdapter extends ArrayAdapter<String> {

    private static class ViewHolder {
        private TextView sms_text;
        private TextView sms_sender;
    }

    public SmsListAdapter(Context context, ArrayList<String> msg) {
        super(context, R.layout.content_sms, msg);
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder = null;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.getContext())
                    .inflate(R.layout.content_sms, parent, false);
            viewHolder = new ViewHolder();
            viewHolder.sms_text = (TextView) convertView.findViewById(R.id.sms_text);
            viewHolder.sms_sender = (TextView) convertView.findViewById(R.id.sms_sender);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (SmsListAdapter.ViewHolder) convertView.getTag();
        }
        //position pair background gris sinon blanc
        if (getItem(position) != null) {
            viewHolder.sms_text.setText(getItem(position).toString());
            viewHolder.sms_sender.setText("TOTO");
        }
        return convertView;
    }
}

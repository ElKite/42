package vtarreau.ft_hangouts.adapter;

import android.content.Context;
import android.provider.ContactsContract;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

import vtarreau.ft_hangouts.Contact;
import vtarreau.ft_hangouts.R;

/**
 * Created by Vincent on 28/11/2016.
 */

public class ContactListAdapter extends ArrayAdapter<Contact> {
    private static class ViewHolder {
        private TextView firstNameView;
        private TextView lastNameView;
        private ImageView photoView;
    }

    public ContactListAdapter(Context context, ArrayList<Contact> contacts) {
        super(context, R.layout.content_main, contacts);
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder = null;
        if (convertView == null) {
            convertView = LayoutInflater.from(this.getContext())
                    .inflate(R.layout.content_main, parent, false);
            viewHolder = new ViewHolder();
            viewHolder.firstNameView = (TextView) convertView.findViewById(R.id.firstname);
            viewHolder.lastNameView = (TextView) convertView.findViewById(R.id.lastname);
            viewHolder.photoView = (ImageView) convertView.findViewById(R.id.photo);
            convertView.setTag(viewHolder);
        } else {
            viewHolder = (ViewHolder) convertView.getTag();
        }
        Contact contact = getItem(position);
        viewHolder.firstNameView.setText(contact.getFirstname());
        viewHolder.lastNameView.setText(contact.getLastname());
        viewHolder.photoView.setImageResource(android.R.drawable.picture_frame);
        return convertView;
    }
}

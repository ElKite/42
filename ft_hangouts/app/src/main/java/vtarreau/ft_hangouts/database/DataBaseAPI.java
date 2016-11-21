package vtarreau.ft_hangouts.database;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.provider.ContactsContract;

import java.util.ArrayList;

import vtarreau.ft_hangouts.Contact;

/**
 * Created by Vincent on 21/11/2016.
 */

public class DataBaseAPI {

    private SQLiteDatabase db;
    private DataBaseHelper dataBaseHelperContacts;

    public DataBaseAPI(Context context) {
        dataBaseHelperContacts = DataBaseHelper.getsInstance(context);
    }

    public void openForWrite() {
        db = dataBaseHelperContacts.getWritableDatabase();
    }

    public void openForRead() {
        db = dataBaseHelperContacts.getReadableDatabase();
    }

    public void close() {
        db.close();
    }

    public void insertContact(Contact contact) {
        ContentValues cv = new ContentValues();
        cv.put(DataBaseHelper.contact_firstname, contact.getFirstname());
        cv.put(DataBaseHelper.contact_lastname, contact.getLastname());
        cv.put(DataBaseHelper.contact_mobile, contact.getMobile());
        cv.put(DataBaseHelper.contact_phone, contact.getPhone());
        cv.put(DataBaseHelper.contact_mail, contact.getMail());
        cv.put(DataBaseHelper.contact_address, contact.getAddress());
        db.insert(DataBaseHelper.ContactTable, null, cv);
    }

    public void updateContact(Contact contact, int id) {
        ContentValues cv = new ContentValues();
        cv.put(DataBaseHelper.contact_firstname, contact.getFirstname());
        cv.put(DataBaseHelper.contact_lastname, contact.getLastname());
        cv.put(DataBaseHelper.contact_mobile, contact.getMobile());
        cv.put(DataBaseHelper.contact_phone, contact.getPhone());
        cv.put(DataBaseHelper.contact_mail, contact.getMail());
        cv.put(DataBaseHelper.contact_address, contact.getAddress());
        db.update(DataBaseHelper.ContactTable, cv, DataBaseHelper.contact_id + " = " + id, null);
    }

    public void removeContact(int id) {
        db.delete(DataBaseHelper.ContactTable, DataBaseHelper.contact_id + " = " + id, null);
    }

    public ArrayList<Contact> getAllContact() {
        if (db == null)
            return null;
        Cursor c = db.rawQuery("SELECT * FROM " + DataBaseHelper.ContactTable, null);
        if (c.getCount() == 0) {
            c.close();
            return null;
        } else {
            ArrayList<Contact> contacts = new ArrayList<Contact>();
            while (c.moveToNext()) {
                Contact contact = new Contact(c);
                contacts.add(contact);
            }
            return contacts;
        }
    }

    public ArrayList<Contact> getAContactFromNames(String name) {
        if (db == null)
            return null;
        Cursor c = db.rawQuery("SELECT * FROM " + DataBaseHelper.ContactTable + " WHERE " +
                DataBaseHelper.contact_firstname + " LIKE " + name + " OR " +
                DataBaseHelper.contact_lastname + " LIKE " + name + " OR " +
                DataBaseHelper.contact_mobile + " LIKE " + name + " OR "+
                DataBaseHelper.contact_phone + " LIKE " + name + " OR " +
                DataBaseHelper.contact_address + " LIKE " + name + " OR " +
                DataBaseHelper.contact_mail + " LIKE " + name, null);
        if (c.getCount() == 0) {
            c.close();
            return null;
        } else {
            ArrayList<Contact> contacts = new ArrayList<Contact>();
            while (c.moveToNext()) {
                Contact contact = new Contact(c);
                contacts.add(contact);
            }
            return contacts;
        }
    }

}

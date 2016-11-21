package vtarreau.ft_hangouts;

import android.database.Cursor;

import vtarreau.ft_hangouts.database.DataBaseHelper;

/**
 * Created by Vincent on 21/11/2016.
 */

public class Contact {

    private String firstname;
    private String lastname;
    private String mobile;
    private String phone;
    private String address;
    private String mail;

    public Contact(String firstname, String lastname, String mobile, String phone, String address,
                   String mail) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.mobile = mobile;
        this.phone = phone;
        this.address = address;
        this.mail = mail;
    }

    public Contact(Cursor c) {
        this.firstname = c.getString(DataBaseHelper.firstname_col);
        this.lastname = c.getString(DataBaseHelper.lastname_col);
        this.mobile = c.getString(DataBaseHelper.mobile_col);
        this.phone = c.getString(DataBaseHelper.phone_col);
        this.address = c.getString(DataBaseHelper.address_col);
        this.mail = c.getString(DataBaseHelper.mail_col);
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public void setMobile(String mobile) {
        this.mobile = mobile;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public String getMobile() {
        return mobile;
    }

    public String getPhone() {
        return phone;
    }

    public String getAddress() {
        return address;
    }

    public String getMail() {
        return mail;
    }
}

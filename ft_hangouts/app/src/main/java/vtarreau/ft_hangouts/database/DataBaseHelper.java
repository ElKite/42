package vtarreau.ft_hangouts.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by Vincent on 21/11/2016.
 */

public class DataBaseHelper extends SQLiteOpenHelper {

    private static final String DB__FILE_NAME = "contact.db";
    private static final int VERSION = 1;

    private static  DataBaseHelper sInstance;
    private SQLiteDatabase db;

    public static final String ContactTable = "Contacts";
    public static final String contact_id = "id";
    public static final String contact_firstname = "firstname";
    public static final String contact_lastname = "lastname";
    public static final String contact_mobile = "mobile";
    public static final String contact_phone = "phone";
    public static final String contact_address = "address";
    public static final String contact_mail = "mail";

    public static final int id_col = 0;
    public static final int firstname_col = 1;
    public static final int lastname_col = 2;
    public static final int mobile_col = 3;
    public static final int phone_col = 4;
    public static final int mail_col = 5;
    public static final int address_col = 6;


    private static final String createContactTable = "CREATE TABLE " + ContactTable + " (" +
            contact_id + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
            contact_firstname + " TEXT NOT NULL, " +
            contact_lastname + " TEXT NOT NULL, " +
            contact_mobile + " TEXT NOT NULL, " +
            contact_phone + " TEXT NOT NULL, " +
            contact_mail + " TEXT NOT NULL, " +
            contact_address + " TEXT NOT NULL " + ");";

    private DataBaseHelper (Context context) {
        super(context, DB__FILE_NAME, null, VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(createContactTable);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {

    }

    public static synchronized  DataBaseHelper getsInstance(Context context) {
        if (sInstance == null) {
            sInstance = new DataBaseHelper(context.getApplicationContext());
        }
        return sInstance;
    }

    public void setsInstance(DataBaseHelper instance) {
        sInstance = instance;
    }
}

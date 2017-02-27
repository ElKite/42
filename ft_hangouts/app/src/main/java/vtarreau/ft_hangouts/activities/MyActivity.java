package vtarreau.ft_hangouts.activities;

import android.app.Activity;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.support.annotation.LayoutRes;
import android.support.annotation.Nullable;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.text.format.Time;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.Toast;

import vtarreau.ft_hangouts.R;

/**
 * Created by Vincent on 24/02/2017.
 */

public class MyActivity extends AppCompatActivity {

    Toolbar toolbar;
    Time time;
    String myTime;
    private static int sessionDepth = 0;
    static final String actionBarColor = "color";

    @Override
    public void setContentView(@LayoutRes int layoutResID) {
        LinearLayout fullView = (LinearLayout) getLayoutInflater().inflate(R.layout.activity_myactivity, null);
        FrameLayout activityContainer = (FrameLayout) fullView.findViewById(R.id.activity_content);
        getLayoutInflater().inflate(layoutResID, activityContainer, true);
        super.setContentView(fullView);
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        time = new Time(Time.getCurrentTimezone());
        time.setToNow();
    }

    public void setToolbar() {

        boolean color;

        toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(getApplicationContext());
        color = sharedPref.getBoolean(actionBarColor, true);
        if (color) {
            toolbar.setBackgroundColor(Color.GREEN);
        } else {
            toolbar.setBackgroundColor(Color.BLUE);
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();
        SharedPreferences sharedPref = PreferenceManager.getDefaultSharedPreferences(getApplicationContext());
        boolean color = sharedPref.getBoolean(actionBarColor, true);

        if (id == R.id.action_settings) {
            SharedPreferences.Editor editor = sharedPref.edit();
            if (color) {
                toolbar.setBackgroundColor(Color.BLUE);
                editor.putBoolean(actionBarColor, false);
                editor.commit();
            }
            else {
                toolbar.setBackgroundColor(Color.GREEN);
                editor.putBoolean(actionBarColor, true);
                editor.commit();
            }
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
        if (sessionDepth > 0)
            sessionDepth--;
        time.setToNow();
        myTime = time.format("%d.%m.%Y %H:%M:%S");
        Log.e("SESSION STOP", Integer.toString(sessionDepth));
    }

    @Override
    protected void onResume() {
        super.onResume();
        sessionDepth++;
        if (sessionDepth == 1) {
            Toast.makeText(getApplicationContext(), myTime, Toast.LENGTH_LONG).show();
        }
        Log.e("SESSION RESUME", Integer.toString(sessionDepth));
    }
}

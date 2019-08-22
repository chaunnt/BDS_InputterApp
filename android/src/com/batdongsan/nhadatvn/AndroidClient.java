package com.batdongsan.nhadatvn;
import java.lang.Thread;
import android.content.res.Resources;
import android.app.Activity;
import android.app.PendingIntent;
import android.database.Cursor;
import android.database.ContentObserver;
import android.database.sqlite.SQLiteException;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ContentValues;
import android.content.BroadcastReceiver;
import android.content.AsyncQueryHandler;
import android.content.ComponentName;
import android.widget.Toast;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.content.ContentUris;
import android.provider.ContactsContract;
import java.util.Date;
import android.os.Environment;
import android.view.View;
import java.io.*;

public class AndroidClient
{

    static long qtObject = 0;
    private static Context m_context = null;
    private static Activity m_activity = null;

    public AndroidClient()
    {
        Log.i("AndroidClient", "AndroidClient Constructor");
    }
    static public void setQtObject(long newQtObject)
    {
        Log.i("AndroidClient", "setQtObject");
        qtObject = newQtObject;
    }
    static public void setActivity(Activity activity)
    {
        Log.i("AndroidClient", "setActivity");
        m_activity = activity;
    }
    static public void setContext(Context context)
    {
        Log.i("AndroidClient", "setContext");
        m_context = context;
    }

    static public void hideClient()
    {
        Intent i= new Intent(Intent.ACTION_MAIN);
        i.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        i.addCategory(Intent.CATEGORY_HOME);
        m_activity.startActivity(i);
    }

    public String captureScreenShot(String strFileName)
    {
//        Date now = new Date();
//        now = android.text.format.DateFormat.format("yyyy-MM-dd_hh:mm:ss", now);
        // image naming and path  to include sd card  appending name you choose for file
        String mPath = strFileName;
        try {
            // create bitmap screen capture
            View v1 = m_activity.getWindow().getDecorView().getRootView();
            v1.setDrawingCacheEnabled(true);
            Bitmap bitmap = Bitmap.createBitmap(v1.getDrawingCache());
            v1.setDrawingCacheEnabled(false);

            File imageFile = new File(mPath);

            FileOutputStream outputStream = new FileOutputStream(imageFile);
            int quality = 100;
            bitmap.compress(Bitmap.CompressFormat.JPEG, quality, outputStream);
            outputStream.flush();
            outputStream.close();
        } catch (Throwable e) {
            // Several error may come out with file handling or DOM
            e.printStackTrace();
        }

        return mPath;
    }
}

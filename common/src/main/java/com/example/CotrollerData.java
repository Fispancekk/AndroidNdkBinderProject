package com.example;

import android.os.Parcel;
import android.os.Parcelable;

public class CotrollerData implements Parcelable
{
    public float[] mCotrollerPosition =new float[3];
    public float[] mCotrollerRotate=new float[4];
    public float[] mTouchPadPosition=new float[2];
    public int mButtonPress=-1;

    public CotrollerData(float[] aCotrollerPosition,float[] aCotrollerRotate,
                         float[] aTouchPadPosition, int aButtonPress)
    {
        mCotrollerPosition = aCotrollerPosition;
        mCotrollerRotate = aCotrollerRotate;
        mTouchPadPosition=aTouchPadPosition;
        mButtonPress=aButtonPress;
    }

    protected CotrollerData(Parcel in)
    {
        in.setDataPosition(4);
        mCotrollerPosition[0] = in.readFloat();
        mCotrollerPosition[1] = in.readFloat();
        mCotrollerPosition[2] = in.readFloat();
        mCotrollerRotate[0] = in.readFloat();
        mCotrollerRotate[1] = in.readFloat();
        mCotrollerRotate[2] = in.readFloat();
        mCotrollerRotate[3] = in.readFloat();
        mTouchPadPosition[0] = in.readFloat();
        mTouchPadPosition[1] = in.readFloat();
        mButtonPress = in.readInt();

    }

    public static final Creator<CotrollerData> CREATOR = new Creator<CotrollerData>()
    {
        @Override
        public CotrollerData createFromParcel(Parcel in)
        {
            return new CotrollerData(in);
        }

        @Override
        public CotrollerData[] newArray(int size)
        {
            return new CotrollerData[size];
        }
    };

    @Override
    public int describeContents()
    {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel parcel, int i)
    {
        parcel.writeFloat(mCotrollerPosition[0]);
        parcel.writeFloat(mCotrollerPosition[1]);
        parcel.writeFloat(mCotrollerPosition[2]);
        parcel.writeFloat(mCotrollerRotate[0]);
        parcel.writeFloat(mCotrollerRotate[1]);
        parcel.writeFloat(mCotrollerRotate[2]);
        parcel.writeFloat(mCotrollerRotate[3]);
        parcel.writeFloat(mTouchPadPosition[0]);
        parcel.writeFloat(mTouchPadPosition[1]);
        parcel.writeInt(mButtonPress);
    }

    @Override
    public String toString()
    {
        StringBuilder str = new StringBuilder();

        str.append("CotrollerData{")
                .append("CotrollerPosition={").append(mCotrollerPosition[0])
                .append(",").append(mCotrollerPosition[1])
                .append(",").append(mCotrollerPosition[2])
                .append("}, CotrollerRotate={").append(mCotrollerRotate[0])
                .append(",").append(mCotrollerRotate[1])
                .append(",").append(mCotrollerRotate[2])
                .append(",").append(mCotrollerRotate[3])
                .append("}, TouchPadPosition={").append(mTouchPadPosition[0])
                .append(",").append(mTouchPadPosition[1])
                .append("}, ButtonPress=").append(mButtonPress);

        return str.toString();
    }
}


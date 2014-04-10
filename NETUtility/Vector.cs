using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Syntax.NETUtility
{
    public class Vector
    {
        public Vector()
        {
            X = 0;
            Y = 0;
            Z = 0;
            W = 0;
        }
        public Vector(float x,float y,float z,float w)
        {
            X = x;
            Y = y;
            Z = z;
            W = w;
        }
        //has to be in format "x y z w" 4 floats seperated by a space
        public Vector(string values)
        {
            string[] strings = values.Split(' ');
            if (strings.Length < 4)
                throw new ArgumentException("string argument to Vector not in proper format");
            X = Int32.Parse(strings[0]);
            Y = Int32.Parse(strings[1]);
            Z = Int32.Parse(strings[2]);
            W = Int32.Parse(strings[3]);
        }
        public float X { get; set; }
        public float Y { get; set; }
        public float Z { get; set; }
        public float W { get; set; }

        public override string ToString()
        {
            return string.Format("{0} {1} {2} {3}",X,Y,Z,W);
        }
    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace rita_rikitaki
{
    public partial class Form1 : Form
    {
        string filename;
        Bitmap myBitmap;
        bool changeoriginal = false, drawing = false, empty = true, isgrey = false;
        int[] colours;
        public static UInt32[,] pixel;
        int howmuch = 50;
        double[,] D = new double[4, 4] { { 0, 8, 2, 10 }, { 12, 4, 14, 6 }, { 3, 11, 1, 9 }, { 15, 7, 13, 5 } };
        int fringe = 100, bottom=100, top=200;
        public Form1()
        {
            InitializeComponent();
        }
        public void movefor4task()
        {
            isgrey = true;
            colours = new int[260];
            for (int i = 0; i < 260; i++)
            {
                colours[i] = 0;
            }
            halftone(0);
        }
        public void halftone(int number)
        {
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    Color curr = myBitmap.GetPixel(x, y);

                    if (number == (0))
                    {
                        Color next = Color.FromArgb((byte)((curr.R + curr.G + curr.B) / 3),
                            (byte)((curr.R + curr.G + curr.B) / 3), (byte)((curr.R + curr.G + curr.B) / 3));
                        colours[(byte)((curr.R + curr.G + curr.B) / 3)]++;
                        myBitmap.SetPixel(x, y, next);
                    }
                    if (number == 1)
                    {
                        Color next = Color.FromArgb(255, (byte)((curr.R + curr.G + curr.B) / 3),
                            (byte)((curr.R + curr.G + curr.B) / 3));
                        myBitmap.SetPixel(x, y, next);
                    }
                    if (number == 2)
                    {
                        Color next = Color.FromArgb((byte)((curr.R + curr.G + curr.B) / 3), 255,
                            (byte)((curr.R + curr.G + curr.B) / 3));
                        myBitmap.SetPixel(x, y, next);
                    }
                    if (number == 3)
                    {
                        Color next = Color.FromArgb((byte)((curr.R + curr.G + curr.B) / 3),
                            (byte)((curr.R + curr.G + curr.B) / 3), 255);
                        myBitmap.SetPixel(x, y, next);
                    }
                    if (number == 4)
                    {
                        Color next = Color.FromArgb((byte)((curr.R + curr.G + curr.B) / 2), 0, 0);
                        myBitmap.SetPixel(x, y, next);
                    }
                    if (number == 5)
                    {
                        Color next = Color.FromArgb(0, (byte)((curr.R + curr.G + curr.B) / 2), 0);
                        myBitmap.SetPixel(x, y, next);
                    }
                    if (number == 6)
                    {
                        Color next = Color.FromArgb(0, 0, (byte)((curr.R + curr.G + curr.B) / 2));
                        myBitmap.SetPixel(x, y, next);
                    }
                }

            }
        }
        public void brightnesschange(int howmuch)
        {
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    Color curr = myBitmap.GetPixel(x, y);
                    int R = curr.R, G = curr.G, B = curr.B;
                    if (howmuch > 0)
                    {
                        R = R + howmuch > 255 ? 255 : R + howmuch;
                        G = G + howmuch > 255 ? 255 : G + howmuch;
                        B = B + howmuch > 255 ? 255 : B + howmuch;
                    }
                    else
                    {
                        R = R + howmuch < 0 ? 0 : R + howmuch;
                        G = G + howmuch < 0 ? 0 : G + howmuch;
                        B = B + howmuch < 0 ? 0 : B + howmuch;
                    }
                    myBitmap.SetPixel(x, y, Color.FromArgb(R, G, B));
                }
            }

            changes();
        }
        public void change1() {  /* pictureBox1.Image = myBitmap;*/ }
        public void change2() { pictureBox2.Image = myBitmap; }
        public void changes() { change1(); change2(); }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            empty = false;
            OpenFileDialog dialog = new OpenFileDialog();
            dialog.Filter = "Image files (*.BMP; *.JPG)|*.bmp;*.jpg";
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                Image image = Image.FromFile(dialog.FileName);
                int width = image.Width, height = image.Height;

                filename = dialog.FileName.ToString();

                myBitmap = new Bitmap(Image.FromFile(dialog.FileName), width, height);

               

                pixel = new UInt32[image.Height, image.Width];
                for (int y = 0; y < image.Height; y++)
                    for (int x = 0; x < image.Width; x++)
                        pixel[y, x] = (UInt32)(myBitmap.GetPixel(x, y).ToArgb());

                pictureBox1.Image = myBitmap;
                pictureBox2.Image = myBitmap;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SaveFileDialog savedialog = new SaveFileDialog();
            savedialog.Title = "Save as";
            savedialog.OverwritePrompt = true;
            savedialog.CheckPathExists = true;
            savedialog.Filter =
                "Bitmap File(*.bmp)|*.bmp|" +
                "GIF File(*.gif)|*.gif";
            savedialog.ShowHelp = true;
            if (savedialog.ShowDialog() == DialogResult.OK)
            {
                string fileName = savedialog.FileName;
                string strFilExtn =
                    fileName.Remove(0, fileName.Length - 3);
                switch (strFilExtn)
                {
                    case "bmp":
                        myBitmap.Save(fileName, System.Drawing.Imaging.ImageFormat.Bmp);
                        break;
                    case "jpg":
                        myBitmap.Save(fileName, System.Drawing.Imaging.ImageFormat.Jpeg);
                        break;
                    default:
                        break;
                }
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    Color curr = myBitmap.GetPixel(x, y);
                    int newcolor;
                    if (curr.R + howmuch < 255 && curr.R + howmuch > 0) newcolor = curr.R + howmuch;
                    else if (curr.R + howmuch > 255) newcolor = 255;
                    else newcolor = 0;
                    myBitmap.SetPixel(x, y, Color.FromArgb(newcolor, curr.G, curr.B));
                }
            }
            changes();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    Color curr = myBitmap.GetPixel(x, y);
                    int newcolor;
                    if (curr.G + howmuch < 255 && curr.G + howmuch > 0) newcolor = curr.G + howmuch;
                    else if (curr.G + howmuch > 255) newcolor = 255;
                    else newcolor = 0;
                    myBitmap.SetPixel(x, y, Color.FromArgb(curr.R, newcolor, curr.B));
                }
            }
            changes();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    Color curr = myBitmap.GetPixel(x, y);
                    int newcolor;
                    if (curr.B + howmuch < 255 && curr.B + howmuch > 0) newcolor = curr.B + howmuch;
                    else if (curr.B + howmuch > 255) newcolor = 255;
                    else newcolor = 0;
                    myBitmap.SetPixel(x, y, Color.FromArgb(curr.R, curr.G, newcolor));
                }
            }
            changes();
        }

        private void button17_Click(object sender, EventArgs e)
        {
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    Color curr = myBitmap.GetPixel(x, y);
                    Color next = Color.FromArgb((byte)(255 - curr.R), (byte)(255 - curr.G), (byte)(255 - curr.B));
                    myBitmap.SetPixel(x, y, next);
                }
            }
            changes();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            brightnesschange(howmuch);

            changes();
        }

        private void button18_Click(object sender, EventArgs e)
        {
            isgrey = true;
            colours = new int[260];
            for (int i = 0; i < 260; i++)
            {
                colours[i] = 0;
            }
            halftone(0);
            changes();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            halftone(1);
            changes();
        }

        private void button19_Click(object sender, EventArgs e)
        {
            halftone(2);
            changes();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            halftone(3);
            changes();
        }

        private void button16_Click(object sender, EventArgs e)
        {
            halftone(4);
            changes();
        }

        private void button22_Click(object sender, EventArgs e)
        {
            halftone(5);
            changes();
        }

        private void button15_Click(object sender, EventArgs e)
        {
            halftone(6);
            changes();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (!isgrey) MessageBox.Show("Need greys");
            else
            {
                if (chart1.Visible) { chart1.Visible = false; pictureBox2.Visible = true; label1.Visible = true; label2.Visible = true; label3.Visible = true; }
                else
                {
                    for (int i = 0; i < 255; i++)
                    {
                        chart1.Series["Image"].Points.AddXY(i, colours[i]);
                    }
                    chart1.Visible = true;
                    pictureBox2.Visible = false;
                    label1.Visible = false; label2.Visible = false; label3.Visible = false;
                }
            }
        }

        private void button13_Click(object sender, EventArgs e)
        {
            pixel = Filter.matrix_filtration(myBitmap.Width, myBitmap.Height, pixel, Filter.N2, Filter.blur);

            for (int y = 0; y < myBitmap.Height; y++)
                for (int x = 0; x < myBitmap.Width; x++)
                    myBitmap.SetPixel(x, y, Color.FromArgb((int)pixel[y, x]));

            changes();
        }

        private void button14_Click(object sender, EventArgs e)
        {
            pixel = Filter.matrix_filtration(myBitmap.Width, myBitmap.Height, pixel, Filter.N1, Filter.sharpness);

            for (int y = 0; y < myBitmap.Height; y++)
                for (int x = 0; x < myBitmap.Width; x++)
                    myBitmap.SetPixel(x, y, Color.FromArgb((int)pixel[y, x]));

            changes();
        }

        private void button21_Click(object sender, EventArgs e)
        {
            pixel = Filter.matrix_filtration(myBitmap.Width, myBitmap.Height, pixel, Filter.N1, Filter.previtt2);

            for (int y = 0; y < myBitmap.Height; y++)
                for (int x = 0; x < myBitmap.Width; x++)
                    myBitmap.SetPixel(x, y, Color.FromArgb((int)pixel[y, x]));

            changes();
        }

        private void button20_Click(object sender, EventArgs e)
        {
            pixel = Filter.matrix_filtration(myBitmap.Width, myBitmap.Height, pixel, Filter.N1, Filter.sobel2);

            for (int y = 0; y < myBitmap.Height; y++)
                for (int x = 0; x < myBitmap.Width; x++)
                    myBitmap.SetPixel(x, y, Color.FromArgb((int)pixel[y, x]));

            changes();
        }

        private void button25_Click(object sender, EventArgs e)
        {
            movefor4task();
            changes();
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R < fringe)
                        myBitmap.SetPixel(x, y, Color.FromArgb(0,0,0));
                }
            }
            changes();
        }

        private void button26_Click(object sender, EventArgs e)
        {
            movefor4task();
            changes();
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R < fringe)
                        myBitmap.SetPixel(x, y, Color.FromArgb(0,0,0));
                }
            }
            changes();
        }

        private void button24_Click(object sender, EventArgs e)
        {
            movefor4task();
            changes();
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R > fringe)
                        myBitmap.SetPixel(x, y, Color.FromArgb(0, 0, 0));
                }
            }
            changes();
        }

        private void button23_Click(object sender, EventArgs e)
        {
            movefor4task();
            changes();
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R > fringe)
                        myBitmap.SetPixel(x, y, Color.FromArgb(255,255,255));
                }
            }
            changes();
        }

        private void button27_Click(object sender, EventArgs e)
        {
            movefor4task();
            changes();
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R > fringe)
                        myBitmap.SetPixel(x, y, Color.FromArgb(255, 255, 255));
                    else myBitmap.SetPixel(x, y, Color.FromArgb(0,0,0));
                }
            }
            changes();
        }

        private void button28_Click(object sender, EventArgs e)
        {
            movefor4task();
            changes();
            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R < fringe)
                        myBitmap.SetPixel(x, y, Color.FromArgb(255, 255, 255));
                    else myBitmap.SetPixel(x, y, Color.FromArgb(0, 0, 0));
                }
            }
            changes();
        }

        private void button32_Click(object sender, EventArgs e)
        {
            movefor4task();

            changes();

            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R > top || myBitmap.GetPixel(x, y).R < bottom)
                        myBitmap.SetPixel(x, y, Color.FromArgb(255 / 2, 255 / 2, 255 / 2));
                    else
                    {
                        Color curr = myBitmap.GetPixel(x, y);
                        int col = curr.R * (top - bottom) / 255;
                        myBitmap.SetPixel(x, y, Color.FromArgb(col, col, col));
                    }
                }
            }

            changes();
        }

        private void button29_Click(object sender, EventArgs e)
        {
            movefor4task();

            changes();

            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R > top || myBitmap.GetPixel(x, y).R < bottom)
                        myBitmap.SetPixel(x, y, Color.FromArgb(0,0,0));
                    else
                    {

                    }
                }
            }

            changes();
        }

        private void button30_Click(object sender, EventArgs e)
        {
            movefor4task();

            changes();

            for (int x = 0; x < myBitmap.Width; x++)
            {
                for (int y = 0; y < myBitmap.Height; y++)
                {
                    if (myBitmap.GetPixel(x, y).R > top || myBitmap.GetPixel(x, y).R < bottom)
                        myBitmap.SetPixel(x, y, Color.FromArgb(255,255,255));
                    else
                    {

                    }
                }
            }

            changes();
        }

        private void button2_Click(object sender, EventArgs e)
        {

            Close();
        }




    }
    class BrightnessContrast
    {
        //якрость
        public static UInt32 Brightness(UInt32 point, int poz, int lenght)
        {
            int R;
            int G;
            int B;

            int N = (100 / lenght) * poz; //кол-во процентов

            R = (int)(((point & 0x00FF0000) >> 16) + N * 128 / 100);
            G = (int)(((point & 0x0000FF00) >> 8) + N * 128 / 100);
            B = (int)((point & 0x000000FF) + N * 128 / 100);

            //контролируем переполнение переменных
            if (R < 0) R = 0;
            if (R > 255) R = 255;
            if (G < 0) G = 0;
            if (G > 255) G = 255;
            if (B < 0) B = 0;
            if (B > 255) B = 255;

            point = 0xFF000000 | ((UInt32)R << 16) | ((UInt32)G << 8) | ((UInt32)B);

            return point;
        }

        //контрастность
        public static UInt32 Contrast(UInt32 point, int poz, int lenght)
        {
            int R;
            int G;
            int B;

            int N = (100 / lenght) * poz; //кол-во процентов

            if (N >= 0)
            {
                if (N == 100) N = 99;
                R = (int)((((point & 0x00FF0000) >> 16) * 100 - 128 * N) / (100 - N));
                G = (int)((((point & 0x0000FF00) >> 8) * 100 - 128 * N) / (100 - N));
                B = (int)(((point & 0x000000FF) * 100 - 128 * N) / (100 - N));
            }
            else
            {
                R = (int)((((point & 0x00FF0000) >> 16) * (100 - (-N)) + 128 * (-N)) / 100);
                G = (int)((((point & 0x0000FF00) >> 8) * (100 - (-N)) + 128 * (-N)) / 100);
                B = (int)(((point & 0x000000FF) * (100 - (-N)) + 128 * (-N)) / 100);
            }

            //контролируем переполнение переменных
            if (R < 0) R = 0;
            if (R > 255) R = 255;
            if (G < 0) G = 0;
            if (G > 255) G = 255;
            if (B < 0) B = 0;
            if (B > 255) B = 255;

            point = 0xFF000000 | ((UInt32)R << 16) | ((UInt32)G << 8) | ((UInt32)B);

            return point;
        }

    }
    class ColorBalance
    {
        //цветовой баланс R
        public static UInt32 ColorBalance_R(UInt32 point, int poz, int lenght)
        {
            int R;
            int G;
            int B;

            int N = (100 / lenght) * poz; //кол-во процентов

            R = (int)(((point & 0x00FF0000) >> 16) + N * 128 / 100);
            G = (int)((point & 0x0000FF00) >> 8);
            B = (int)(point & 0x000000FF);

            //контролируем переполнение переменных
            if (R < 0) R = 0;
            if (R > 255) R = 255;

            point = 0xFF000000 | ((UInt32)R << 16) | ((UInt32)G << 8) | ((UInt32)B);

            return point;
        }

        //цветовой баланс G
        public static UInt32 ColorBalance_G(UInt32 point, int poz, int lenght)
        {
            int R;
            int G;
            int B;

            int N = (100 / lenght) * poz; //кол-во процентов

            R = (int)((point & 0x00FF0000) >> 16);
            G = (int)(((point & 0x0000FF00) >> 8) + N * 128 / 100);
            B = (int)(point & 0x000000FF);

            //контролируем переполнение переменных
            if (G < 0) G = 0;
            if (G > 255) G = 255;

            point = 0xFF000000 | ((UInt32)R << 16) | ((UInt32)G << 8) | ((UInt32)B);

            return point;
        }

        //цветовой баланс B
        public static UInt32 ColorBalance_B(UInt32 point, int poz, int lenght)
        {
            int R;
            int G;
            int B;

            int N = (100 / lenght) * poz; //кол-во процентов

            R = (int)((point & 0x00FF0000) >> 16);
            G = (int)((point & 0x0000FF00) >> 8);
            B = (int)((point & 0x000000FF) + N * 128 / 100);

            //контролируем переполнение переменных
            if (B < 0) B = 0;
            if (B > 255) B = 255;

            point = 0xFF000000 | ((UInt32)R << 16) | ((UInt32)G << 8) | ((UInt32)B);

            return point;
        }

    }
    struct RGB
    {
        public float R;
        public float G;
        public float B;
    }
    class Filter
    {
        public static UInt32[,] matrix_filtration(int W, int H, UInt32[,] pixel, int N, double[,] matryx)
        {
            int i, j, k, m, gap = (int)(N / 2);
            int tmpH = H + 2 * gap, tmpW = W + 2 * gap;
            UInt32[,] tmppixel = new UInt32[tmpH, tmpW];
            UInt32[,] newpixel = new UInt32[H, W];
            //заполнение временного расширенного изображения
            //углы
            for (i = 0; i < gap; i++)
                for (j = 0; j < gap; j++)
                {
                    tmppixel[i, j] = pixel[0, 0];
                    tmppixel[i, tmpW - 1 - j] = pixel[0, W - 1];
                    tmppixel[tmpH - 1 - i, j] = pixel[H - 1, 0];
                    tmppixel[tmpH - 1 - i, tmpW - 1 - j] = pixel[H - 1, W - 1];
                }
            //крайние левая и правая стороны
            for (i = gap; i < tmpH - gap; i++)
                for (j = 0; j < gap; j++)
                {
                    tmppixel[i, j] = pixel[i - gap, j];
                    tmppixel[i, tmpW - 1 - j] = pixel[i - gap, W - 1 - j];
                }
            //крайние верхняя и нижняя стороны
            for (i = 0; i < gap; i++)
                for (j = gap; j < tmpW - gap; j++)
                {
                    tmppixel[i, j] = pixel[i, j - gap];
                    tmppixel[tmpH - 1 - i, j] = pixel[H - 1 - i, j - gap];
                }
            //центр
            for (i = 0; i < H; i++)
                for (j = 0; j < W; j++)
                    tmppixel[i + gap, j + gap] = pixel[i, j];
            //применение ядра свертки
            RGB ColorOfPixel = new RGB();
            RGB ColorOfCell = new RGB();
            for (i = gap; i < tmpH - gap; i++)
                for (j = gap; j < tmpW - gap; j++)
                {
                    ColorOfPixel.R = 0;
                    ColorOfPixel.G = 0;
                    ColorOfPixel.B = 0;
                    for (k = 0; k < N; k++)
                        for (m = 0; m < N; m++)
                        {
                            ColorOfCell = calculationOfColor(tmppixel[i - gap + k, j - gap + m], matryx[k, m]);
                            ColorOfPixel.R += ColorOfCell.R;
                            ColorOfPixel.G += ColorOfCell.G;
                            ColorOfPixel.B += ColorOfCell.B;
                        }
                    //контролируем переполнение переменных
                    if (ColorOfPixel.R < 0) ColorOfPixel.R = 0;
                    if (ColorOfPixel.R > 255) ColorOfPixel.R = 255;
                    if (ColorOfPixel.G < 0) ColorOfPixel.G = 0;
                    if (ColorOfPixel.G > 255) ColorOfPixel.G = 255;
                    if (ColorOfPixel.B < 0) ColorOfPixel.B = 0;
                    if (ColorOfPixel.B > 255) ColorOfPixel.B = 255;

                    newpixel[i - gap, j - gap] = build(ColorOfPixel);
                }

            return newpixel;
        }

        //вычисление нового цвета
        public static RGB calculationOfColor(UInt32 pixel, double coefficient)
        {
            RGB Color = new RGB();
            Color.R = (float)(coefficient * ((pixel & 0x00FF0000) >> 16));
            Color.G = (float)(coefficient * ((pixel & 0x0000FF00) >> 8));
            Color.B = (float)(coefficient * (pixel & 0x000000FF));
            return Color;
        }

        //сборка каналов
        public static UInt32 build(RGB ColorOfPixel)
        {
            UInt32 Color;
            Color = 0xFF000000 | ((UInt32)ColorOfPixel.R << 16) | ((UInt32)ColorOfPixel.G << 8) | ((UInt32)ColorOfPixel.B);
            return Color;
        }


        public const int N1 = 3;
        public static double[,] sharpness = new double[N1, N1] {{-1, -1, -1},
                                                               {-1,  9, -1},
                                                               {-1, -1, -1}};

        public const int N2 = 3;
        public static double[,] blur = new double[N1, N1] {{0.111, 0.111, 0.111},
                                                               {0.111, 0.111, 0.111},
                                                               {0.111, 0.111, 0.111}};
        public const int N3 = 3;
        public const int N222 = 2;
        public static double[,] roberts = new double[N222, N222] {{-1, 0},
                                                               {0, 1}};

        public static double[,] previtt1 = new double[N1, N1] {{-1, 0, 1},
                                                               {-1, 0, 1},
                                                               {-1, 0, 1}};

        public static double[,] mine = new double[N1, N1] {{0, 0, 0},
                                                               {1, 1, 1},
                                                               {0, 0, 0}};

        public static double[,] previtt2 = new double[N1, N1] {{-1, -1, -1},
                                                               {0, 0, 0},
                                                               {1, 1, 1}};

        public static double[,] sobel1 = new double[N1, N1] {{-1, 0, 1},
                                                               {-2, 0, 2},
                                                               {-1, 0, 1}};
        public static double[,] sobel2 = new double[N1, N1] {{-1, -2, -1},
                                                               {0, 0, 0},
                                                               {1, 2, 1}};
        public static double[,] tisn = new double[N1, N1] {{0, 1, 0},
                                                               {-1, 0, 1},
                                                               {0, -1, 0}};
    }
}

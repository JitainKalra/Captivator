using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Net.Mail;
using AForge.Video.DirectShow;
using AForge.Video;

namespace GarbageMonitoring
{
    public partial class Form1 : Form
    {
        FilterInfoCollection _fInfoCollection;
        VideoCaptureDevice _vCaptureDevice;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
               
                serialPort1.PortName = Program.com;
                serialPort1.BaudRate = 9600;
                serialPort1.Open();

            }
            catch (Exception _exception)
            {
                MessageBox.Show("Sorry something went wrong" + _exception);
            }        
            
            

        }
        int i = 0;
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
           string val=serialPort1.ReadLine();
           MessageBox.Show(val);
           string v = val.Substring(0, 1);
           if (v == "A")
           {
               MessageBox.Show("a");
               string per = val.Substring(2, 2);
               email_send("Dustbin A has been full " + per + "%");


           }
           if (v == "B")
           {

               MessageBox.Show("b");
               string per = val.Substring(2, 2);
               email_send("Dustbin B has been full " + per + "%");

           }
            
           //foreach (string str in value)
           //{
           //    MessageBox.Show(str);
           //}
          
        }

        public void email_send(string body)
        {
            MailMessage mail = new MailMessage();
            SmtpClient SmtpServer = new SmtpClient("smtp.gmail.com");
            mail.From = new MailAddress("Dummydustbin7@gmail.com");
            mail.To.Add("Dummydustbin7@gmail.com");
            mail.Subject = "The Dustbin is about to be full";
            mail.Body = body;

            //System.Net.Mail.Attachment attachment;
           // attachment = new System.Net.Mail.Attachment("E:\\Img.jpg");
           // mail.Attachments.Add(attachment);

            SmtpServer.Port = 587;
            SmtpServer.Credentials = new System.Net.NetworkCredential("Dummydustbin7@gmail.com", "dummydust7");
            SmtpServer.EnableSsl = true;

            SmtpServer.Send(mail);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            _vCaptureDevice = new VideoCaptureDevice(_fInfoCollection[comboBox1.SelectedIndex].MonikerString);
            _vCaptureDevice.NewFrame += new NewFrameEventHandler(get_Frame);
            _vCaptureDevice.Start(); 
        }
        private void get_Frame(object sender, NewFrameEventArgs eventArgs)
        {
            //Insert image into Picuture Box
            Bitmap _BsourceFrame = (Bitmap)eventArgs.Frame.Clone();
            pictureBox1.Image = _BsourceFrame;
        }
    }
}

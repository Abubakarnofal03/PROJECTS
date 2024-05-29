using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using Oracle.ManagedDataAccess.Client;
using System.Collections;

namespace WindowsFormsApp5
        
{
    public partial class Form1 : Form
    {
        OracleConnection con;
        //1st button
        Label description = new Label();
        TextBox a = new TextBox();
        Button back = new Button();
        Label date = new Label();
        TextBox b = new TextBox();
        Label time = new Label();
        TextBox c = new TextBox();
        Label location = new Label();
        TextBox d = new TextBox();
        TextBox d1 = new TextBox();
        Label ed = new Label();
        TextBox ed1 = new TextBox();
        //2nd button
        Label np = new Label();
        TextBox np1 = new TextBox();
        Label pi = new Label();
        TextBox pi1 = new TextBox();
        Label ei = new Label();
        TextBox ei1 = new TextBox();

        //admin button
        Label username = new Label();
        TextBox us = new TextBox();
        Label name = new Label();
        TextBox n = new TextBox();
        Label email = new Label();
        TextBox e = new TextBox();

        //admin button
       
        Label password = new Label();
        TextBox pass = new TextBox();
        Label eventid = new Label();
        TextBox eventb = new TextBox();
        Label eid = new Label();
        TextBox sid = new TextBox();
        Label status = new Label();
        TextBox stf = new TextBox();
        Label se = new Label();
        TextBox se1 = new TextBox();
        Label sp = new Label();
        TextBox sp1 = new TextBox();
        Label ss = new Label();
        TextBox ss1 = new TextBox();
        Button del= new Button();
        Button update= new Button();
        public Form1()
        {

            InitializeComponent();
            sub11.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            pr.Visible = false;
            ec.Visible = false;
            adminbutton.Visible = false;
            userbutton.Visible = false;
            button11.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            bacck.Visible = false;
            dataGridView1.Visible = false;
            this.Controls.Add(dataGridView1);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            string conStr = @"DATA SOURCE = localhost:1521/xe;USER ID=NIGGA1;PASSWORD=nigga";
            con=new OracleConnection(conStr);
            button11.Visible = false;
            bacck.Visible = false;
        }


        private void updateGrid()
        {
            con.Open(); 
            OracleCommand getEmps=con.CreateCommand();
            getEmps.CommandText = "SELECT * FROM event ";
            getEmps.CommandType=CommandType.Text;   
            OracleDataReader empDR=getEmps.ExecuteReader();
            DataTable empDT =new DataTable();
            empDT.Load(empDR);
            dataGridView1.DataSource=empDT;
            con.Close();
            dataGridView1.Visible = true;
        }
        private void updateGrid22()
        {
            try
            {
                con.Open();
                string query = "SELECT * FROM event WHERE event_id = :event_id";
                using (OracleCommand getEmps = new OracleCommand(query, con))
                {
                    // Adding the parameter to the command
                    getEmps.Parameters.Add(new OracleParameter("event_id", de.Text));

                    getEmps.CommandType = CommandType.Text;
                    using (OracleDataReader empDR = getEmps.ExecuteReader())
                    {
                        DataTable empDT = new DataTable();
                        empDT.Load(empDR);
                        dataGridView1.DataSource = empDT;
                    }
                }
                dataGridView1.Visible = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
            finally
            {
                con.Close();
            }
        }
        private void updateGrid222()
        {
            con.Open();
            OracleCommand getEmps = con.CreateCommand();
            getEmps.CommandText = " SELECT e.event_id,  COUNT(p.P_id) AS ParticipantCount FROM Event e LEFT OUTER JOIN Participants p ON e.event_id = p.e_id GROUP BY e.event_id";
     
            getEmps.CommandType = CommandType.Text;
            OracleDataReader empDR = getEmps.ExecuteReader();
            DataTable empDT = new DataTable();
            empDT.Load(empDR);
            dataGridView1.DataSource = empDT;
            con.Close();
            dataGridView1.Visible = true;
        }
        private void updateGrid2222()
        {
            con.Open();
            OracleCommand getEmps = con.CreateCommand();
            getEmps.CommandText = " SELECT e.event_id, COUNT(s.s_id) AS NumberOfSpeakers FROM event e INNER JOIN speakers s ON e.event_id = s.e_id GROUP BY e.event_id";

            getEmps.CommandType = CommandType.Text;
            OracleDataReader empDR = getEmps.ExecuteReader();
            DataTable empDT = new DataTable();
            empDT.Load(empDR);
            dataGridView1.DataSource = empDT;
            con.Close();
            dataGridView1.Visible = true;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            


        }
        void submission()
        {

        }
        private void button7_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            

        }

        private void button3_Click(object sender, EventArgs e)
        {
           
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {

            
            }

        private void ec_Click(object sender, EventArgs e)
        {
            aa++;
            um.Visible = true;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            pr.Visible = false;
            button11.Visible = true;
            ec.Visible = false;
            description.Visible = true;
            description.Text = "Description";
            description.AutoSize = true;
            description.BackColor = Color.White;
            description.Location = new Point(69, 100);
            this.Controls.Add(description);

            a.Visible = true;
            // description.Text = "Description";
            a.AutoSize = true;
            a.BackColor = Color.White;
            a.Location = new Point(199, 100);
            this.Controls.Add(a);

            date.Visible = true;
            date.Text = "Date";
            date.AutoSize = true;
            date.BackColor = Color.White;
            date.Location = new Point(69, 140);
            this.Controls.Add(date);

            b.Visible = true;
            // description.Text = "Description";
            b.AutoSize = true;
            b.BackColor = Color.White;
            b.Location = new Point(199, 140);
            this.Controls.Add(b);

            time.Visible = true;
            time.Text = "Time";
            time.AutoSize = true;
            time.BackColor = Color.White;
            time.Location = new Point(69, 180);
            this.Controls.Add(time);

            c.Visible = true;
            // description.Text = "Description";
            c.AutoSize = true;
            c.BackColor = Color.White;
            c.Location = new Point(199, 180);
            this.Controls.Add(c);

            location.Visible = true;
            location.Text = "event_id";
            location.AutoSize = true;
            location.BackColor = Color.White;
            location.Location = new Point(69, 220);
            this.Controls.Add(location);

            d1.Visible = true;
            // description.Text = "Description";
            d1.AutoSize = true;
            d1.BackColor = Color.White;
            d1.Location = new Point(199, 220);
            this.Controls.Add(d1);




        }

        int aa = 0,bb=0;
        private void button4_Click(object sender, EventArgs e)
        {
            bb++;
            dataGridView1.Visible = false;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            pr.Visible = false;
            sub11.Visible = true;
            ec.Visible = false;
            description.Visible = true;
            description.Text = "Description";
            description.AutoSize = true;
            description.BackColor = Color.White;
            description.Location = new Point(69, 100);
            this.Controls.Add(description);
          //  eventid.Visible = true;
            eventid.Text = "Event_id";
            eventid.AutoSize = true;
            eventid.BackColor = Color.White;
            //eventid.Location = new Point(89, 100);
           // this.Controls.Add(eventid);

            a.Visible = true;
            // description.Text = "Description";
            a.AutoSize = true;
            a.BackColor = Color.White;
            a.Location = new Point(199, 100);
            this.Controls.Add(a);

            date.Visible = true;
            date.Text = "Date";
            date.AutoSize = true;
            date.BackColor = Color.White;
            date.Location = new Point(69, 140);
            this.Controls.Add(date);

            b.Visible = true;
            // description.Text = "Description";
            b.AutoSize = true;
            b.BackColor = Color.White;
            b.Location = new Point(199, 140);
            this.Controls.Add(b);

            time.Visible = true;
            time.Text = "Time";
            time.AutoSize = true;
            time.BackColor = Color.White;
            time.Location = new Point(69, 180);
            this.Controls.Add(time);

            c.Visible = true;
            // description.Text = "Description";
            c.AutoSize = true;
            c.BackColor = Color.White;
            c.Location = new Point(199, 180);
            this.Controls.Add(c);

            location.Visible = true;
            location.Text = "event_id";
            location.AutoSize = true;
            location.BackColor = Color.White;
            location.Location = new Point(69, 220);
            this.Controls.Add(location);

            d.Visible = true;
            // description.Text = "Description";
            d.AutoSize = true;
            d.BackColor = Color.White;
            d.Location = new Point(199, 220);
            this.Controls.Add(d);

            
        }

        private void btnInsert_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into event Values ('" + d1.Text.ToString() +"','" +a.Text.ToString() + "', '" + c.Text.ToString() + "', '" + b.Text.ToString()  +  "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();5
        }


        private void btndelete_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "delete from speakers where s_id = "+ed1.Text.ToString();
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data deleted successfully");
            }
            con.Close();
           // updateGrid();
        }


        private void button11_Click(object sender, EventArgs e)
        {

            //button11.Visible = true;
            if (us.Text != "a")
            {
                bacck.Visible = false;
                MessageBox.Show("user not found");
                adminbutton_Click(sender, e);
            }
            else
            {
                MessageBox.Show("done");
                

                this.Controls.Clear();
                InitializeComponent();
                dataGridView1.Visible = false;
                bacck.Visible = false;
                button11.Visible = false;
                button19.Visible = false;
                adminbutton.Visible = false;
                userbutton.Visible = false;
                sub11.Visible = false;
                button200.Visible = false;
                button300.Visible = false;
                um.Visible = true;
                if (aa > 0)
                {
                    btnInsert_Click(sender, e);
                    aa = 0;
                }
                else if (ee > 0)
                {
                    updateGrid22();

                }
                else if (pp > 0)
                {
                    btnInsert_Click1(sender, e);
                    pp = 0;
                }
                else if (temp> 0)
                {
                    btnInsert_Click2(sender, e);
                    temp = 0;
                }
               
            }
            
        }

        int cc = 0;
        private void button200_Click(object sender, EventArgs e)
        {
            cc++;
            dataGridView1.Visible = false;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pr.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            ec.Visible = false;
            sub11.Visible = true;
            this.Controls.Add(button11);
            


            name.Visible = true;
            name.Text = "e_id";
            name.AutoSize = true;
            name.BackColor = Color.White;
            name.Location = new Point(69, 105);
            this.Controls.Add(name);

            n.Visible = true;

            n.AutoSize = true;
            n.BackColor = Color.White;
            n.Location = new Point(199, 100);
            this.Controls.Add(n);

            date.Visible = true;
            date.Text = "p_id";
            date.AutoSize = true;
            date.BackColor = Color.White;
            date.Location = new Point(69, 155);
            this.Controls.Add(date);
            d.Visible = true;

            d.AutoSize = true;
            d.BackColor = Color.White;
            d.Location = new Point(199, 150);
            this.Controls.Add(d);
            np.Visible = true;
            np.Text = "Name";
            np.AutoSize = true;
            np.BackColor = Color.White;
            np.Location = new Point(69, 185);
            this.Controls.Add(np);
            np1.Visible = true;

            np1.AutoSize = true;
            np1.BackColor = Color.White;
            np1.Location = new Point(199, 185);
            this.Controls.Add(np1);
        }
       // int sd = 0;
        private void scd_Click(object sender, EventArgs e)
        {
            //  sd++;

            updateGrid();
            
        }
        private void btnInsert_Click2(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into speakers Values ('" + sp1.Text.ToString() + "','" + se1.Text.ToString() + "', '" + ss1.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
        }
        int temp = 0;
        private void sm_Click(object sender, EventArgs e)
        {
            temp++;
            button11.Visible = true;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pr.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            ec.Visible = false;
            sub11.Visible = true;
            name.Visible = false;
            n.Visible = false;
            date.Visible = false;
            d.Visible = false;
            sub11.Visible = false;
            this.Controls.Add(button11);
            


            se.Visible = true;
            se.Text = "event_id";
            se.AutoSize = true;
            se.BackColor = Color.White;
            se.Location = new Point(69, 105);
            this.Controls.Add(se);

            se1.Visible = true;

            se1.AutoSize = true;
            se1.BackColor = Color.White;
            se1.Location = new Point(199, 100);
            this.Controls.Add(se1);

            ss.Visible = true;
            ss.Text = "no.speakers";
            ss.AutoSize = true;
            ss.BackColor = Color.White;
            ss.Location = new Point(69, 155);
            this.Controls.Add(ss);
            ss1.Visible = true;

            ss1.AutoSize = true;
            ss1.BackColor = Color.White;
            ss1.Location = new Point(199, 150);
            this.Controls.Add(ss1);
           
            sp.Text = "s_id";
            sp.Visible = true;
            sp.AutoSize = true;
            sp.BackColor = Color.White;
            sp.Location = new Point(69, 186);
            this.Controls.Add(sp);
            sp1.Visible = true;

            sp1.AutoSize = true;
            sp1.BackColor = Color.White;
            sp1.Location = new Point(199, 186);
            this.Controls.Add(sp1);
        }

        private void button19_Click(object sender, EventArgs e)
        {

            adminbutton.Visible = true;
            userbutton.Visible = true;
            button19.Visible = false;
        }
        private void bbtnInsert_Click1(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into PARTICIPANTS Values ('" + d.Text.ToString() + "','" + n.Text.ToString() + "', '" + np1.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
        }

        private void sub11_Click(object sender, EventArgs e)
        {

            this.Controls.Clear();
            InitializeComponent();
            button11.Visible = false;
            button19.Visible = false;
            adminbutton.Visible = false;
            userbutton.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            button11.Visible = false;
            ec.Visible = true;
            pr.Visible = true;
            sub11.Visible = true;
            bacck.Visible = false;
            if (bb > 0)
            {
                 bbtnInsert_Click(sender, e);
                bb = 0;
            }
            else if (cc>0)
            {
                bbtnInsert_Click1(sender , e);
                cc = 0;

            }
            dataGridView1.Visible = false;
            // 
        }
        private void bbtnInsert_Click(object sender, EventArgs e)
        {
            con.Open();
            OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into event Values ('" + d.Text.ToString() + "','" + a.Text.ToString() + "', '" + c.Text.ToString() + "', '" + b.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
        }

        private void adminbutton_Click(object sender, EventArgs e)
        {
            bacck.Visible = false;
            adminbutton.Visible = false;
            userbutton.Visible = false;
            username.Visible = true;
            username.Text = "username";
            username.AutoSize = true;
            username.BackColor = Color.White;
            username.Location = new Point(69, 105);
            this.Controls.Add(username);

            us.Visible = true;

            us.AutoSize = true;
            us.BackColor = Color.White;
            us.Location = new Point(199, 105);
            this.Controls.Add(us);


            password.Text = "password";
            password.AutoSize = true;
            password.BackColor = Color.White;
            password.Location = new Point(69, 140);
            password.Visible = true;
            this.Controls.Add(password);


            pass.AutoSize = true;
            pass.BackColor = Color.White;
            pass.Location = new Point(199, 140);
            pass.Visible = true;
            string a = pass.Text;
            if (a == "123")
            {
                MessageBox.Show("Asd");
            }
            this.Controls.Add(pass);
            button11.Visible = true;
        }

        private void userbutton_Click(object sender, EventArgs e)
        {
            bacck.Visible = false;
            adminbutton.Visible = false;
            userbutton.Visible = false;
            username.Visible = true;
            username.Text = "username";
            username.AutoSize = true;
            username.BackColor = Color.White;
            username.Location = new Point(69, 105);
            this.Controls.Add(username);

            us.Visible = true;

            us.AutoSize = true;
            us.BackColor = Color.White;
            us.Location = new Point(199, 100);
            this.Controls.Add(us);

            password.Visible = true;
            password.Text = "password";
            password.AutoSize = true;
            password.BackColor = Color.White;
            password.Location = new Point(69, 140);
            this.Controls.Add(password);
           
            pass.Visible = true;

            pass.AutoSize = true;
            pass.BackColor = Color.White;
            pass.Location = new Point(199, 140);
            this.Controls.Add(pass);
            button11.Visible = false;
            sub11.Visible = true;

        }

        private void bacck_Click(object sender, EventArgs e)
        {
            button19_Click(sender, e);
            username.Visible = false;
            us.Visible = false;
            password.Visible = false;
            pass.Visible = false;
            bacck.Visible = false;
            button11.Visible = false;
        }

        private void button1000_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Thanks for coming \n For feedback mail on abc@gmail.com");
            Environment.Exit(0);
        }
        
        private void btnInsert_Click1(object sender, EventArgs e)
        {
            con.Open();             OracleCommand insertEmp = con.CreateCommand();
            insertEmp.CommandText = "Insert into PARTICIPANTS Values ('" +d.Text.ToString() + "','" + n.Text.ToString() + "', '" + np.Text.ToString() + "')";
            insertEmp.CommandType = CommandType.Text;
            int rows = insertEmp.ExecuteNonQuery();
            if (rows > 0)
            {
                MessageBox.Show("Data inserted successfully");
            }
            con.Close();
        }
        int pp = 0;
        private void pr_Click(object sender, EventArgs e)
        {
          
            pp++;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pr.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            ec.Visible = false;
            button11.Visible = true;
            this.Controls.Add(button11);
           


            name.Visible = true;
            name.Text = "e_id";
            name.AutoSize = true;
            name.BackColor = Color.White;
            name.Location = new Point(69, 105);
            this.Controls.Add(name);

            n.Visible = true;

            n.AutoSize = true;
            n.BackColor = Color.White;
            n.Location = new Point(199, 100);
            this.Controls.Add(n);

            date.Visible = true;
            date.Text = "p_id";
            date.AutoSize = true;
            date.BackColor = Color.White;
            date.Location = new Point(69, 155);
            this.Controls.Add(date);
            d.Visible = true;

            d.AutoSize = true;
            d.BackColor = Color.White;
            d.Location = new Point(199, 150);
            this.Controls.Add(d);

            np.Visible = true;
            np.Text = "Name";
            np.AutoSize = true;
            np.BackColor = Color.White;
            np.Location = new Point(69, 185);
            this.Controls.Add(np);
            np1.Visible = true;

            np1.AutoSize = true;
            np1.BackColor = Color.White;
            np1.Location = new Point(199, 185);
            this.Controls.Add(np1);
            

        }

        Button e_id=new Button();
        TextBox de=new TextBox();
        int ee = 0;
        private void pm_Click(object sender, EventArgs e)
        {
            ee++;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            pr.Visible = false;
            sub11.Visible = false;
            ec.Visible = false;
            e_id.Visible = true;
            e_id.Text = "e_id";
            e_id.AutoSize = true;
            e_id.BackColor = Color.White;
            e_id.Location = new Point(69, 155);
            this.Controls.Add(e_id);
            de.Visible = true;
           button11.Visible = true;
            de.AutoSize = true;
            de.BackColor = Color.White;
            de.Location = new Point(69, 190);
            this.Controls.Add(de);

        }

        private void um_Click(object sender, EventArgs e)
        {
            um.Visible = false;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            pr.Visible = false;
            button11.Visible = false;
            ec.Visible = false;
            description.Visible = false;
            button79.Visible = true;
            button89.Visible = true;    
        }
        int dele = 0;
        private void button79_Click(object sender, EventArgs e)
        {
            dele++;
            button89.Visible = false;   
            button79.Visible = false;
            ed.Visible = true;
            ed.Text = "s_id";
            ed.AutoSize = true;
            ed.BackColor = Color.White;
            ed.Location = new Point(69, 105);
            this.Controls.Add(ed);

            ed1.Visible = true;

            ed1.AutoSize = true;
            ed1.BackColor = Color.White;
            ed1.Location = new Point(199, 100);
            this.Controls.Add(ed1);
            button999.Visible = true;
            this.Controls.Add(button999); 
        }

        private void button999_Click(object sender, EventArgs e)
        {
            if (dele > 0)
            {
                btndelete_Click(sender, e);
            }
            button19_Click(sender, e);
            ed.Visible = false;
            ed1.Visible = false;
            button999.Visible= false;
        }

        private void button89_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            updateGrid222();
        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            updateGrid2222();
        }

        private void r_Click(object sender, EventArgs e)
        {
            um.Visible = false;
            bacck.Visible = false;
            button200.Visible = false;
            button300.Visible = false;
            pm.Visible = false;
            scd.Visible = false;
            sm.Visible = false;
            r.Visible = false;
            um.Visible = false;
            pr.Visible = false;
            button11.Visible = false;
            ec.Visible = false;
            description.Visible = false;
            button79.Visible = false;
            button89.Visible = false;
            button2000.Visible = true;
            button3000.Visible = true;

        }
    }

        
}
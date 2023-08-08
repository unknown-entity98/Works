import javax.swing.*;
public class simple{
    JFrame f;
    simple(){
        f = new JFrame();//creating instance of JButton
        JButton b = new JButton("Here");
        b.setBounds(100,100,100,140);

        f.add(b);//adding buttong in JFrame

        f.setSize(600,600);
        f.setLayout(null);
        f.setVisible(true);
        //System.out.println(f.getSize());
        System.out.println(f.getSize());
    }

    public static void main(String[] args){
        new simple();
    }
}
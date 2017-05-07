package tech.matthorn.gui;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import javax.swing.border.Border;

public class DemoFrame extends JFrame {

    private static final long serialVersionUID = 6087142813503144790L;
    private static final int BORDER_WIDTH = 8;
    
    private Border makeBorder() {
        return makeBorder(BORDER_WIDTH);
    }
    
    private Border makeBorder(int width) {
        return BorderFactory.createEmptyBorder(width, width, width, width);
    }

    public DemoFrame() {
        super("GUI Sample Application");
        getContentPane().setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        
        JLabel label1 = new JLabel("Text & Button");
        label1.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        label1.setBorder(makeBorder());
        add(label1);
        
        Box textButtonBox = new Box(BoxLayout.X_AXIS);
        JTextField textBox = new JTextField();
        textBox.setAlignmentY(JComponent.TOP_ALIGNMENT);
        textButtonBox.add(textBox);
        JButton button = new JButton("Press Me");
        button.addActionListener(e -> System.out.println("Button Pressed. Entered text: " + textBox.getText()));
        button.setAlignmentY(JComponent.TOP_ALIGNMENT);
        textButtonBox.add(button);
        textButtonBox.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        textButtonBox.setBorder(makeBorder());
        add(textButtonBox);
        
        JLabel label2 = new JLabel("Combo Box");
        label2.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        label2.setBorder(makeBorder());
        add(label2);
        
        String options[] = {"A", "B", "C"};
        JComboBox<String> comboBox = new JComboBox<>(options);
        comboBox.addActionListener(e -> System.out.println("Combo Box Changed. Selected item: " + comboBox.getSelectedItem()));
        comboBox.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        Box comboBoxWrapper = new Box(BoxLayout.X_AXIS);
        comboBoxWrapper.add(comboBox);
        comboBoxWrapper.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        comboBoxWrapper.setBorder(makeBorder());
        add(comboBoxWrapper);
        
        JLabel label3 = new JLabel("Basic Input Widgets");
        label3.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        label3.setBorder(makeBorder());
        add(label3);
        Box widgetBox = new Box(BoxLayout.X_AXIS);
        widgetBox.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        JCheckBox checkBox = new JCheckBox("Check Box");
        checkBox.addActionListener(e -> System.out.println("Check box " + (checkBox.isSelected() ? "" : "un") + "checked"));
        widgetBox.add(checkBox);
        
        ButtonGroup radioButtonGroup = new ButtonGroup();
        JRadioButton radioOne = new JRadioButton("One");
        radioOne.addActionListener(e -> {
            if (radioOne.isSelected()) System.out.println("Radio One checked");
        });
        radioButtonGroup.add(radioOne);
        widgetBox.add(radioOne);
        JRadioButton radioTwo = new JRadioButton("Two");
        radioTwo.addActionListener(e -> {
            if (radioTwo.isSelected()) System.out.println("Radio Two checked");
        });
        radioButtonGroup.add(radioTwo);
        widgetBox.add(radioTwo);
        JSlider slider = new JSlider();
        slider.addChangeListener(e -> System.out.println("Slider slid to " + slider.getValue()));
        widgetBox.add(slider);
        JSpinner spinner = new JSpinner(new SpinnerNumberModel(0, 0, 100, 1));
        spinner.addChangeListener(e -> System.out.println("Spinner spun to " + spinner.getValue()));
        widgetBox.add(spinner);
        widgetBox.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        widgetBox.setBorder(makeBorder());
        add(widgetBox);
        
        JLabel label4 = new JLabel("Scrollable List");
        label4.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        label4.setBorder(makeBorder());
        add(label4);
        
        Box list = new Box(BoxLayout.Y_AXIS);
        for (char c = 'A'; c <= 'L'; c++) {
            JLabel l = new JLabel("" + c);
            l.setAlignmentX(JComponent.LEFT_ALIGNMENT);
            l.setBorder(makeBorder(15));
            list.add(l);
        }
        JScrollPane listPane = new JScrollPane(list);
        listPane.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        Box listPaneWrapper = new Box(BoxLayout.X_AXIS);
        listPaneWrapper.add(listPane);
        listPaneWrapper.setAlignmentX(JComponent.LEFT_ALIGNMENT);
        listPaneWrapper.setBorder(makeBorder());
        add(listPaneWrapper);
    }

    public static void main(String[] args) {
        DemoFrame f = new DemoFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(700, 600);
        f.setVisible(true);
    }

}

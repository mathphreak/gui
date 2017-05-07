// Based on wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include <wx/spinctrl.h>
#include <iostream>
using namespace std;

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    wxTextCtrl * textBox;
    wxComboBox * comboBox;
    wxCheckBox * checkBox;
    wxRadioButton * radioOne;
    wxRadioButton * radioTwo;
    wxSlider * slider;
    wxSpinCtrl * spinner;

    void OnButtonClicked(wxCommandEvent &);
    void OnComboBox(wxCommandEvent &);
    void OnCheckBox(wxCommandEvent &);
    void OnRadio(wxCommandEvent &);
    void OnSlide(wxCommandEvent &);
    void OnSpin(wxCommandEvent &);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("GUI Sample Application", wxPoint(50, 50), wxSize(722, 598));
    frame->Show(true);
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size) {
    wxBoxSizer * topsizer = new wxBoxSizer(wxVERTICAL);

    topsizer->Add(new wxStaticText(this, wxID_ANY, "Text && Button"), wxSizerFlags(0).Left().Border());

    wxBoxSizer * textButtonSizer = new wxBoxSizer(wxHORIZONTAL);
    textBox = new wxTextCtrl(this, wxID_ANY);
    textButtonSizer->Add(textBox, wxSizerFlags(1).Border());
    wxButton * button = new wxButton(this, wxID_ANY, "Press Me");
    button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
    textButtonSizer->Add(button, wxSizerFlags(0).Border());
    topsizer->Add(textButtonSizer, wxSizerFlags(0).Expand());

    topsizer->Add(new wxStaticText(this, wxID_ANY, "Combo Box"), wxSizerFlags(0).Left().Border());

    const wxString comboBoxEntries[] = { "A", "B", "C" };
    comboBox = new wxComboBox(this, wxID_ANY, "A", wxDefaultPosition, wxDefaultSize, 3, comboBoxEntries, wxCB_READONLY);
    comboBox->Bind(wxEVT_COMBOBOX, &MyFrame::OnComboBox, this);
    topsizer->Add(comboBox, wxSizerFlags(0).Expand().Border());

    topsizer->Add(new wxStaticText(this, wxID_ANY, "Basic Input Widgets"), wxSizerFlags(0).Left().Border());

    wxBoxSizer * widgetSizer = new wxBoxSizer(wxHORIZONTAL);
    checkBox = new wxCheckBox(this, wxID_ANY, "Check Box");
    checkBox->Bind(wxEVT_CHECKBOX, &MyFrame::OnCheckBox, this);
    widgetSizer->Add(checkBox, wxSizerFlags(0).Border());
    radioOne = new wxRadioButton(this, wxID_ANY, "One");
    radioOne->Bind(wxEVT_RADIOBUTTON, &MyFrame::OnRadio, this);
    widgetSizer->Add(radioOne, wxSizerFlags(0).Border());
    radioTwo = new wxRadioButton(this, wxID_ANY, "Two");
    radioTwo->Bind(wxEVT_RADIOBUTTON, &MyFrame::OnRadio, this);
    widgetSizer->Add(radioTwo, wxSizerFlags(0).Border());
    slider = new wxSlider(this, wxID_ANY, 50, 0, 100);
    slider->Bind(wxEVT_SLIDER, &MyFrame::OnSlide, this);
    widgetSizer->Add(slider, wxSizerFlags(1).Border());
    spinner = new wxSpinCtrl(this, wxID_ANY);
    spinner->Bind(wxEVT_SPINCTRL, &MyFrame::OnSpin, this);
    widgetSizer->Add(spinner, wxSizerFlags(0).Border());
    topsizer->Add(widgetSizer, wxSizerFlags(0).Expand());

    topsizer->Add(new wxStaticText(this, wxID_ANY, "Scrollable List"), wxSizerFlags(0).Left().Border());

    wxScrolledWindow * listWindow = new wxScrolledWindow(this);
    listWindow->SetScrollRate(0, 5);
    wxBoxSizer * list = new wxBoxSizer(wxVERTICAL);
    for (char c = 'A'; c <= 'L'; c++) {
        list->Add(new wxStaticText(listWindow, wxID_ANY, c), wxSizerFlags(0).Left().Border(wxALL, 10));
    }
    listWindow->SetSizer(list);
    topsizer->Add(listWindow, wxSizerFlags(1).Expand());

    SetSizer(topsizer);
}

void MyFrame::OnButtonClicked(wxCommandEvent &) {
    cout << "Button Pressed. Entered text: " << textBox->GetValue() << endl;
}

void MyFrame::OnComboBox(wxCommandEvent &) {
    cout << "Combo Box Changed. Selected item: " << comboBox->GetValue() << endl;
}

void MyFrame::OnCheckBox(wxCommandEvent &) {
    cout << "Check box ";
    if (!checkBox->GetValue()) {
        cout << "un";
    }
    cout << "checked" << endl;
}

void MyFrame::OnRadio(wxCommandEvent &) {
    cout << "Radio ";
    if (radioOne->GetValue()) {
        cout << "One";
    } else if (radioTwo->GetValue()) {
        cout << "Two";
    }
    cout << " checked" << endl;
}

void MyFrame::OnSlide(wxCommandEvent &) {
    cout << "Slider slid to " << slider->GetValue() << endl;
}

void MyFrame::OnSpin(wxCommandEvent &) {
    cout << "Spinner spun to " << spinner->GetValue() << endl;
}

#ifdef _WIN32
int main() {
    WinMain(NULL, NULL, NULL, 0);
}
#endif

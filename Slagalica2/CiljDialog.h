#pragma once


// CiljDialog dialog

class CiljDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CiljDialog)

public:
	CiljDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CiljDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int I;
	int J;
};

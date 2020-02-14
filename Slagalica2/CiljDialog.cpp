// CiljDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Slagalica2.h"
#include "CiljDialog.h"
#include "afxdialogex.h"


// CiljDialog dialog

IMPLEMENT_DYNAMIC(CiljDialog, CDialogEx)

CiljDialog::CiljDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, I(0)
	, J(0)
{

}

CiljDialog::~CiljDialog()
{
}

void CiljDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, I);
	DDV_MinMaxInt(pDX, I, 0, 3);
	DDX_Text(pDX, IDC_EDIT2, J);
	DDV_MinMaxInt(pDX, J, 0, 3);
}


BEGIN_MESSAGE_MAP(CiljDialog, CDialogEx)
END_MESSAGE_MAP()


// CiljDialog message handlers

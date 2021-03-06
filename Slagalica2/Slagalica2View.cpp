
// Slagalica2View.cpp : implementation of the CSlagalica2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Slagalica2.h"
#endif

#include "Slagalica2Doc.h"
#include "Slagalica2View.h"
#include "CiljDialog.h"
#include <string>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSlagalica2View

IMPLEMENT_DYNCREATE(CSlagalica2View, CView)

BEGIN_MESSAGE_MAP(CSlagalica2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CSlagalica2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_PROMENI_CILJ, &CSlagalica2View::OnPromeniCilj)
	ON_COMMAND(ID_FILE_NEW, &CSlagalica2View::OnFileNew)
END_MESSAGE_MAP()

// CSlagalica2View construction/destruction

CSlagalica2View::CSlagalica2View()
{
	// TODO: add construction code here

}

CSlagalica2View::~CSlagalica2View()
{
}

BOOL CSlagalica2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSlagalica2View drawing

void CSlagalica2View::OnDraw(CDC* pDC)
{
	CSlagalica2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect mainFrame;
	GetClientRect(&mainFrame);
	// calculate fields
	lengthX = mainFrame.Width() / 4;
	lengthY = mainFrame.Height() / 4;

	vector<vector<char>> matrica = GetDocument()->matrica;

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	pDC->SelectObject(&pen);

	// basic drawing lines
	for (int i = 0; i <= 4; i++)
	{
		pDC->MoveTo(0, i*lengthY);
		pDC->LineTo(4 * lengthX, i*lengthY);

		pDC->MoveTo(i*lengthX, 0);
		pDC->LineTo(i*lengthX, 4 * lengthY);
	}

	int halfLengthX = lengthX / 2;
	int halfLengthY = lengthY / 2;

	CPen green(PS_SOLID, 1, RGB(0, 250, 0));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			string s(1, matrica[i][j]);
			CString s1(s.c_str());

			pDC->TextOutW(halfLengthX + halfLengthX * 2 * j, halfLengthY + halfLengthY * 2 * i, s1);
			if ((pDoc->polje1 && pDoc->trenutna1.x==i && pDoc->trenutna1.y==j)
				||(pDoc->polje2 && pDoc->trenutna2.x == i && pDoc->trenutna2.y == j))
			{
				// drawing arrow
				pDC->SelectObject(&green);

				if (i > 0) {
					pDC->MoveTo(j * lengthX + 0.5 * lengthX, i * lengthY - 2);
					pDC->LineTo(j * lengthX + 0.5 * lengthX, i * lengthY - lengthY * 0.4);
					pDC->LineTo(j * lengthX + 0.4 * lengthX, i * lengthY - lengthY * 0.2);
					pDC->MoveTo(j * lengthX + 0.5 * lengthX, i * lengthY - lengthY * 0.4);
					pDC->LineTo(j * lengthX + 0.6 * lengthX, i * lengthY - lengthY * 0.2);
				}

				if (i < 3) {
					pDC->MoveTo(j * lengthX + 0.5 * lengthX, (i + 1) * lengthY + 2);
					pDC->LineTo(j * lengthX + 0.5 * lengthX, (i + 1) * lengthY + lengthY * 0.4);
					pDC->LineTo(j * lengthX + 0.4 * lengthX, (i + 1) * lengthY + lengthY * 0.2);
					pDC->MoveTo(j * lengthX + 0.5 * lengthX, (i + 1) * lengthY + lengthY * 0.4);
					pDC->LineTo(j * lengthX + 0.6 * lengthX, (i + 1) * lengthY + lengthY * 0.2);
				}

				if (j > 0) {
					pDC->MoveTo(j * lengthX - 2,  i * lengthY + 0.5 * lengthY);
					pDC->LineTo(j * lengthX - 0.4 * lengthX, i * lengthY + 0.5 * lengthY);
					pDC->LineTo(j * lengthX - 0.2 * lengthX, i * lengthY + 0.3 * lengthY);
					pDC->MoveTo(j * lengthX - 0.4 * lengthX, i * lengthY + 0.5 * lengthY);
					pDC->LineTo(j * lengthX - 0.2 * lengthX, i * lengthY + 0.7 * lengthY);
				}

				if (j < 3) {
					pDC->MoveTo((j + 1) * lengthX + 2, i * lengthY + 0.5 * lengthY);
					pDC->LineTo((j + 1) * lengthX + 0.4 * lengthX, i * lengthY + 0.5 * lengthY);
					pDC->LineTo((j + 1) * lengthX + 0.2 * lengthX, i * lengthY + 0.3 * lengthY);
					pDC->MoveTo((j + 1) * lengthX + 0.4 * lengthX, i * lengthY + 0.5 * lengthY);
					pDC->LineTo((j + 1) * lengthX + 0.2 * lengthX, i * lengthY + 0.7 * lengthY);
				}
				pDC->SelectObject(&pen);
			}
		}
	}

	

}


// CSlagalica2View printing


void CSlagalica2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CSlagalica2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSlagalica2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSlagalica2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CSlagalica2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CSlagalica2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CSlagalica2View diagnostics

#ifdef _DEBUG
void CSlagalica2View::AssertValid() const
{
	CView::AssertValid();
}

void CSlagalica2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSlagalica2Doc* CSlagalica2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSlagalica2Doc)));
	return (CSlagalica2Doc*)m_pDocument;
}
#endif //_DEBUG


// CSlagalica2View message handlers


void CSlagalica2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CSlagalica2Doc* pDC = GetDocument();
	// changing selected field and move that field
	switch (nChar) {
	case '1':
		pDC->polje1 = true;
		if(pDC->polje2)
			pDC->polje2 = false;
		break;
	case '2':
		pDC->polje2 = true;
		if (pDC->polje1)
			pDC->polje1 = false;
		break;
	case VK_UP:
		if (pDC->polje1)
			pDC->gore(true);
		else
			if (pDC->polje2)
				pDC->gore(false);
		break;
	case VK_DOWN:
		if (pDC->polje1)
			pDC->dole(true);
		else
			if (pDC->polje2)
				pDC->dole(false);
		break;
	case VK_LEFT:
		if (pDC->polje1)
			pDC->levo(true);
		else
			if (pDC->polje2)
				pDC->levo(false);
		break;
	case VK_RIGHT:
		if (pDC->polje1)
			pDC->desno(true);
		else
			if (pDC->polje2)
				pDC->desno(false);
		break;
	}

	Invalidate();
	if (pDC->proveri()) // if A is placed on target field
	{
		AfxMessageBox(L"A je dospelo na ciljnu poziciju.");
		pDC->restart();
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CSlagalica2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	int x = point.x;
	int y = point.y;

	int j = x / lengthX;
	int i = y / lengthY;
	// changing selected field
	if (i == GetDocument()->trenutna1.x && j == GetDocument()->trenutna1.y)
	{
		GetDocument()->polje1 = true;
		GetDocument()->polje2 = false;
		Invalidate();
		return;
	}
	if (i == GetDocument()->trenutna2.x && j == GetDocument()->trenutna2.y)
	{
		GetDocument()->polje2 = true;
		GetDocument()->polje1 = false;
		Invalidate();
		return;
	}
	// test, change and update for target field
	if (GetDocument()->polje1)
	{
		if ((i == GetDocument()->trenutna1.x && abs(GetDocument()->trenutna1.y - j) == 1)
			|| (j == GetDocument()->trenutna1.y && abs(GetDocument()->trenutna1.x - i) == 1))
		{
			if (GetDocument()->trenutna1 != GetDocument()->trenutna2)
			{
				swap(GetDocument()->matrica[GetDocument()->trenutna1.x][GetDocument()->trenutna1.y], GetDocument()->matrica[i][j]);
				GetDocument()->trenutna1.x = i;
				GetDocument()->trenutna1.y = j;
				Invalidate();
				if (GetDocument()->proveri())
				{
					// if A is placed on target field
					AfxMessageBox(L"A je dospelo na ciljnu poziciju.");
					GetDocument()->restart();
					Invalidate();
				}
			}
		}
		else
		{
			GetDocument()->polje1 = false;
			Invalidate();
		}
	} else
		if (GetDocument()->polje2)
		{
			if ((i == GetDocument()->trenutna2.x && abs(GetDocument()->trenutna2.y - j) == 1)
				|| (j == GetDocument()->trenutna2.y && abs(GetDocument()->trenutna2.x - i) == 1))
			{
				if (GetDocument()->trenutna1 != GetDocument()->trenutna2)
				{

					swap(GetDocument()->matrica[GetDocument()->trenutna2.x][GetDocument()->trenutna2.y], GetDocument()->matrica[i][j]);
					GetDocument()->trenutna2.x = i;
					GetDocument()->trenutna2.y = j;
					Invalidate();
					if (GetDocument()->proveri())
					{
						// if A is placed on target field
						AfxMessageBox(L"A je dospelo na ciljnu poziciju.");
						GetDocument()->restart();
						Invalidate();
					}
				}
			}
			else
			{
				GetDocument()->polje2 = false;
				Invalidate();
			}
		}

	CView::OnLButtonDown(nFlags, point);
}


void CSlagalica2View::OnPromeniCilj()
{
	// changing target field
	CiljDialog d = new CiljDialog();
	d.I = GetDocument()->ciljna.x;
	d.J = GetDocument()->ciljna.y;

	if (d.DoModal() == IDOK) {

		if (GetDocument()->matrica[d.I][d.J] != 'A')
		{
			GetDocument()->ciljna.x = d.I;
			GetDocument()->ciljna.y = d.J;
			AfxMessageBox(L"Uspesno ste promenili ciljnu poziciju");
		}
		else
			AfxMessageBox(L"Na ovoj poziciji se vec nalazi A!");
	}
}


void CSlagalica2View::OnFileNew()
{	// restart game
	GetDocument()->restart();
	Invalidate();
}

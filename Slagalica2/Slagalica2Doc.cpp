/*
	Created by Stefan Sokolovic 2017
*/

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Slagalica2.h"
#endif

#include "Slagalica2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSlagalica2Doc

IMPLEMENT_DYNCREATE(CSlagalica2Doc, CDocument)

BEGIN_MESSAGE_MAP(CSlagalica2Doc, CDocument)
END_MESSAGE_MAP()


// CSlagalica2Doc construction/destruction

CSlagalica2Doc::CSlagalica2Doc()
{
	// TODO: add one-time construction code here
	restart();
}

CSlagalica2Doc::~CSlagalica2Doc()
{
	
}

void CSlagalica2Doc::restart()
{
	// definition and initialization of fields
	matrica.resize(4);
	for (int i = 0; i < 4; i++)
		matrica[i].resize(4);
	ciljna.x = 2;
	ciljna.y = 1;
	trenutna1.x = 0;
	trenutna1.y = 1;
	trenutna2.x = 1;
	trenutna2.y = 2;
	polje1 = false;
	polje2 = false;
	matrica[0][0] = 'A';
	matrica[0][1] = ' ';
	matrica[0][2] = 'B';
	matrica[0][3] = 'C';
	matrica[1][0] = 'D';
	matrica[1][1] = 'E';
	matrica[1][2] = ' ';
	matrica[1][3] = 'F';
	matrica[2][0] = 'G';
	matrica[2][1] = 'H';
	matrica[2][2] = 'I';
	matrica[2][3] = 'J';
	matrica[3][0] = 'K';
	matrica[3][1] = 'L';
	matrica[3][2] = 'M';
	matrica[3][3] = 'N';
}
 // up
void CSlagalica2Doc::gore(bool prvo)
{
	if (prvo)
	{
		if (trenutna1.x > 0 && !(trenutna2.x == trenutna1.x - 1 && trenutna2.y == trenutna1.y))
		{
			swap(matrica[trenutna1.x][trenutna1.y], matrica[trenutna1.x - 1][trenutna1.y]);
			trenutna1.x = trenutna1.x - 1;
		}
	}
	else
		if (trenutna2.x > 0 && !(trenutna1.x == trenutna2.x - 1 && trenutna2.y == trenutna1.y))
		{
			swap(matrica[trenutna2.x][trenutna2.y], matrica[trenutna2.x - 1][trenutna2.y]);
			trenutna2.x = trenutna2.x - 1;
		}

}
// down
void CSlagalica2Doc::dole(bool prvo)
{
	if (prvo)
	{
		if (trenutna1.x < 3 && !(trenutna2.x == trenutna1.x + 1 && trenutna2.y == trenutna1.y))
		{
			swap(matrica[trenutna1.x][trenutna1.y], matrica[trenutna1.x + 1][trenutna1.y]);
			trenutna1.x = trenutna1.x + 1;
		}
	}
	else
		if (trenutna2.x < 3 && !(trenutna1.x == trenutna2.x + 1 && trenutna2.y == trenutna1.y))
		{
			swap(matrica[trenutna2.x][trenutna2.y], matrica[trenutna2.x + 1][trenutna2.y]);
			trenutna2.x = trenutna2.x + 1;
		}
}
// left
void CSlagalica2Doc::levo(bool prvo)
{
	if (prvo)
	{
		if (trenutna1.y > 0 && !(trenutna2.y == trenutna1.y - 1 && trenutna1.x == trenutna2.x))
		{
			swap(matrica[trenutna1.x][trenutna1.y], matrica[trenutna1.x][trenutna1.y - 1]);
			trenutna1.y = trenutna1.y - 1;
		}
	}
	else
		if (trenutna2.y > 0 && !(trenutna1.y == trenutna2.y - 1 && trenutna1.x == trenutna2.x))
		{
			swap(matrica[trenutna2.x][trenutna2.y], matrica[trenutna2.x][trenutna2.y - 1]);
			trenutna2.y = trenutna2.y - 1;
		}
}
// right
void CSlagalica2Doc::desno(bool prvo)
{
	if (prvo)
	{
		if (trenutna1.y < 3 && !(trenutna2.y == trenutna1.y + 1 && trenutna1.x == trenutna2.x))
		{
			swap(matrica[trenutna1.x][trenutna1.y], matrica[trenutna1.x][trenutna1.y + 1]);
			trenutna1.y = trenutna1.y + 1;
		}
	}
	else
		if (trenutna2.y < 3 && !(trenutna1.y == trenutna2.y + 1 && trenutna1.x == trenutna2.x))
		{
			swap(matrica[trenutna2.x][trenutna2.y], matrica[trenutna2.x][trenutna2.y + 1]);
			trenutna2.y = trenutna2.y + 1;
		}
}

bool CSlagalica2Doc::proveri() // test is it correct target
{
	if (matrica[ciljna.x][ciljna.y] == 'A')
		return true;
	else return false;
}

BOOL CSlagalica2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSlagalica2Doc serialization

void CSlagalica2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSlagalica2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CSlagalica2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSlagalica2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSlagalica2Doc diagnostics

#ifdef _DEBUG
void CSlagalica2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSlagalica2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSlagalica2Doc commands

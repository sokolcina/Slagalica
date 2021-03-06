
// Slagalica2View.h : interface of the CSlagalica2View class
//

#pragma once


class CSlagalica2View : public CView
{
protected: // create from serialization only
	CSlagalica2View();
	DECLARE_DYNCREATE(CSlagalica2View)

// Attributes
public:
	CSlagalica2Doc* GetDocument() const;
	int lengthX{ 0 }, lengthY{ 0 };
// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSlagalica2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPromeniCilj();
	afx_msg void OnFileNew();
};

#ifndef _DEBUG  // debug version in Slagalica2View.cpp
inline CSlagalica2Doc* CSlagalica2View::GetDocument() const
   { return reinterpret_cast<CSlagalica2Doc*>(m_pDocument); }
#endif



// Slagalica2Doc.h : interface of the CSlagalica2Doc class
//
#include<vector>

using namespace std;

#pragma once


class CSlagalica2Doc : public CDocument
{
protected: // create from serialization only
	CSlagalica2Doc();
	DECLARE_DYNCREATE(CSlagalica2Doc)

// Attributes
public:
	vector<vector<char>> matrica; // matrix fields
	CPoint ciljna, trenutna1, trenutna2; // target field, first temporary field, second temporary field
	bool polje1, polje2; // temporary selected field
// Operations
public:
	void restart();
	void gore(bool prvo);
	void dole(bool prvo);
	void levo(bool prvo);
	void desno(bool prvo);
	bool proveri();
// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CSlagalica2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};

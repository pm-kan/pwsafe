/*
 * Copyright (c) 2003-2021 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file PWFiltersDateDlg.h
* 
*/

#ifndef _PWFILTERSDATEDLG_H_
#define _PWFILTERSDATEDLG_H_

/*!
 * Includes
 */

#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/datetime.h>
#include <wx/dateevt.h>
#include <wx/datectrl.h>

#include "PWSFilters.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_COMBOBOX64 10365
#define ID_DATECTRL65 10366
#define ID_DATECTRL66 10367
#define ID_SPINCTRL67 10368
#define ID_SPINCTRL68 10369
#define ID_RADIO_BT_ON 10370
#define ID_RADIO_BT_IN 10371
////@end control identifiers

#define PW_NUM_PRESENT_ENUM 2
#define PW_NUM_DATE_CRITERIA_ENUM 5

/*!
 * pwFiltersDateDlg class declaration
 */

class pwFiltersDateDlg : public wxDialog
{
  DECLARE_CLASS(pwFiltersDateDlg)
  DECLARE_EVENT_TABLE()

public:
  /// Constructors
  pwFiltersDateDlg(wxWindow* parent, FieldType ftype, PWSMatch::MatchRule &rule, time_t &fdate1, time_t &fdate2, int &fnum1, int &fnum2, int &fdatetype);

  /// Destructor
  virtual ~pwFiltersDateDlg();

  /// Creation
  bool Create(wxWindow* parent);

  /// Initialises member variables
  void Init();

  /// Creates the controls and sizers
  void CreateControls();

  /// Retrieves bitmap resources
  wxBitmap GetBitmapResource( const wxString& name );

  /// Retrieves icon resources
  wxIcon GetIconResource( const wxString& name );

  /// Should we show tooltips?
  static bool ShowToolTips();

private:

  void InitDialog();
  void SetValidators();

  //(*Handlers(pwFiltersDateDlg)
  void OnOk(wxCommandEvent& event);
  void OnSelectionChange(wxCommandEvent& event);
  void OnExpDate1Changed(wxDateEvent& event);
  void OnExpDate2Changed(wxDateEvent& event);
  void OnFNum1Change(wxSpinEvent& event);
  void OnFNum2Change(wxSpinEvent& event);
  void OnRadiobuttonOnSelected(wxCommandEvent& event);
  void OnRadiobuttonInSelected(wxCommandEvent& event);
  //*)
  
  void CheckControls();
  bool CheckBetween(bool showMessage);
  bool isRuleSelected(PWSMatch::MatchRule rule);
  void UpdateUnitSelection();

  //(*Declarations(pwFiltersDateDlg)
  wxComboBox* m_ComboBox;
  wxDatePickerCtrl* m_ExpDate1Ctrl;
  wxDatePickerCtrl* m_ExpDate2Ctrl;
  wxSpinCtrl* m_FNum1Ctrl;
  wxSpinCtrl* m_FNum2Ctrl;
  wxRadioButton* m_OnCtrl;
  wxRadioButton* m_InCtrl;
  //*)

  enum { PW_DATE_ABS = 0, PW_DATE_REL = 1 }; // values for int m_fdatetype
  
  int m_idx;
  wxDateTime m_fdate1;
  wxDateTime m_fdate2;
  int m_fnum1;
  int m_fnum2;
  int m_fdatetype;
  int m_min;
  int m_max;
  
  const FieldType m_ftype;
  bool m_add_present;
  // Result parameter
  PWSMatch::MatchRule *m_prule;
  time_t              *m_pfdate1;
  time_t              *m_pfdate2;
  int                 *m_pfnum1;
  int                 *m_pfnum2;
  int                 *m_pfdatetype;
  
  static const PWSMatch::MatchRule m_mrpres[PW_NUM_PRESENT_ENUM];
  static const PWSMatch::MatchRule m_mrcrit[PW_NUM_DATE_CRITERIA_ENUM];
};

#endif // _PWFILTERSDATEDLG_H_

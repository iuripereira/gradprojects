object OKBottomDlg: TOKBottomDlg
  Left = 809
  Top = 275
  BorderStyle = bsDialog
  Caption = 'Criar Subscription'
  ClientHeight = 214
  ClientWidth = 313
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object OKBtn: TButton
    Left = 79
    Top = 180
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 159
    Top = 180
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 297
    Height = 161
    Caption = 'EventSubscription'
    TabOrder = 2
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 31
      Height = 13
      Caption = 'Nome:'
    end
    object Label2: TLabel
      Left = 8
      Top = 64
      Width = 53
      Height = 13
      Caption = 'Buffer: (ms)'
    end
    object Label3: TLabel
      Left = 80
      Top = 64
      Width = 43
      Height = 13
      Caption = 'MaxSize:'
    end
    object Button1: TButton
      Left = 136
      Top = 128
      Width = 75
      Height = 25
      Caption = 'Criar'
      Enabled = False
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 8
      Top = 40
      Width = 121
      Height = 21
      Enabled = False
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 8
      Top = 80
      Width = 57
      Height = 21
      Enabled = False
      TabOrder = 2
    end
    object Edit3: TEdit
      Left = 80
      Top = 80
      Width = 49
      Height = 21
      Enabled = False
      TabOrder = 3
    end
  end
end

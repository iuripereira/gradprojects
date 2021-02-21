object OKBottomDlg1: TOKBottomDlg1
  Left = 456
  Top = 347
  BorderStyle = bsDialog
  Caption = 'Subscription'
  ClientHeight = 175
  ClientWidth = 264
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 249
    Height = 161
    Caption = 'EventSubscription'
    TabOrder = 0
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
      Left = 128
      Top = 64
      Width = 43
      Height = 13
      Caption = 'MaxSize:'
    end
    object nomeTxt: TEdit
      Left = 8
      Top = 40
      Width = 233
      Height = 21
      TabOrder = 0
      Text = 'Teste'
    end
    object bufferTxt: TEdit
      Left = 8
      Top = 80
      Width = 105
      Height = 21
      TabOrder = 1
      Text = '1000'
    end
    object maxSizeTxt: TEdit
      Left = 128
      Top = 80
      Width = 113
      Height = 21
      TabOrder = 2
      Text = '150'
    end
    object OKBtn: TButton
      Left = 39
      Top = 120
      Width = 75
      Height = 25
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 3
      OnClick = OKBtnClick
    end
    object CancelBtn: TButton
      Left = 127
      Top = 120
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 4
      OnClick = CancelBtnClick
    end
  end
end

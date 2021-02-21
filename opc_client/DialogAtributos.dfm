object dialogAttributes: TdialogAttributes
  Left = 264
  Top = 139
  BorderStyle = bsDialog
  Caption = 'Atributos'
  ClientHeight = 551
  ClientWidth = 704
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 681
    Height = 497
    Shape = bsFrame
  end
  object OKBtn: TButton
    Left = 535
    Top = 516
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 615
    Top = 516
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object listEventCat: TListBox
    Left = 16
    Top = 16
    Width = 657
    Height = 121
    ItemHeight = 13
    TabOrder = 2
    OnClick = listEventCatClick
  end
  object ListAttributes: TListView
    Left = 16
    Top = 152
    Width = 337
    Height = 337
    Columns = <
      item
        Caption = 'ID'
      end
      item
        Caption = 'Descri'#231#227'o'
      end
      item
        Caption = 'Tipo'
      end
      item
        Caption = 'Event Category'
      end>
    HideSelection = False
    MultiSelect = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 3
  end
  object ListAttributesEscolhidos: TListView
    Left = 408
    Top = 152
    Width = 265
    Height = 345
    Columns = <
      item
        Caption = 'ID'
      end
      item
        Caption = 'Descri'#231#227'o'
      end
      item
        Caption = 'Tipo'
      end
      item
        Caption = 'Event Category'
      end>
    HideSelection = False
    ReadOnly = True
    RowSelect = True
    TabOrder = 4
  end
  object btAdd: TButton
    Left = 360
    Top = 200
    Width = 33
    Height = 25
    Caption = '>>'
    TabOrder = 5
    OnClick = btAddClick
  end
  object btRemove: TButton
    Left = 360
    Top = 232
    Width = 33
    Height = 25
    Caption = '<<'
    TabOrder = 6
    OnClick = btRemoveClick
  end
end

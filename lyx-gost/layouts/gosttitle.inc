# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal André <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.
# Split from stdstruct.inc by Hartmut Goebel <hartmut@noris.net>

# Cut & paste from various LyX layouts plus some major modifications
# GOST textclass (c) 2001 Vitaly Lipatov, Boris Balabanov
# Vitaly Lipatov (c) 2007
# Our parts licensed under GPL
# This include files contains all layouts that handle the title area
# a document, like title, author and such.

Format 4
# Title style definition
#Style Наим_организации
Style НаимОрганизации
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gosttitlecompany
  ParSkip		0.4
  ItemSep		0
  TopSep		0
  BottomSep		1
  ParSep		1
  Align			Center
  AlignPossible		Center
  LabelType		No_Label

  # standard font definition
  Font 
    Size		Largest
  EndFont

End


# Гриф согласования
#Style Гриф_Cогласовано
Style ГрифСогласовано
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gostgrifsoglasovano
  ParSkip		0.4
  ItemSep		0
  TopSep		0
  BottomSep		1
  ParSep		1
  Align			Left
  AlignPossible		Left
  LabelType		No_Label


  # standard font definition
  Font 
    Size		Normal
  EndFont

End

# Гриф утверждения
#Style Гриф_Утверждения
Style ГрифУтверждения
  Margin		Right_Address_Box
  LatexType		Command
  InTitle		1
  LatexName		gostgrifutverjdeno
  ParSkip		0.4
  ItemSep		0
  TopSep		0
  BottomSep		1
  ParSep		1
  Align			Left
  AlignPossible		Left
  LabelType		No_Label

  # standard font definition
  Font 
    Size		Normal
  EndFont

End


# Title style definition
#Style Наим_изделия
Style НаимИзделия
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gosttitleobject
  ParSkip		0.4
  ItemSep		0
  TopSep		0
  BottomSep		1
  ParSep		1
  Align			Center
  AlignPossible		Center
  LabelType		No_Label

  # standard font definition
  Font 
    Size		Largest
  EndFont

End


# Title style definition
#Style Наим_документа
Style НаимДокумента
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gosttitledocument
  ParSkip		0.4
  ItemSep		0
  TopSep		0
  BottomSep		1
  ParSep		1
  Align			Center
  AlignPossible		Center
  LabelType		No_Label

  # standard font definition
  Font 
    Size		Large
  EndFont

End


# Title style definition
Style Обозначение
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gostoboznachenie
  ParSkip		0.4
  ItemSep		0
  TopSep		0
  BottomSep		1
  ParSep		1
  Align			Center
  AlignPossible		Center
  LabelType		No_Label
  LabelString   "КЛГИ:"

  # standard font definition
  Font 
    Size		Largest
  EndFont
End

# Title style definition
Style Разработал
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gostrazrabotchik
  ParSkip		3
  ItemSep		0
  TopSep		0
  BottomSep		0
  ParSep		0
  Align			Left
  AlignPossible		Left
  LeftMargin            MMMMMMMMMMMMM
  LabelType		Static
  LabelString   "Разработал: "

  # standard font definition
  Font 
    Size		Normal
  EndFont
  LabelFont 
    Size		Normal
	Color		red
  EndFont
End


# Title style definition
Style Проверил
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gostproveril
  ParSkip		0.0
  ItemSep		0
  TopSep		0
  BottomSep		0
  ParSep		0
  Align			Left
  AlignPossible		Left
  LeftMargin            MMMMMMMMMMMMM
  LabelType		Static
  LabelString   "Проверил: "

  # standard font definition
  Font 
    Size		Normal
  EndFont
  LabelFont 
    Size		Normal
	Color		red
  EndFont
End

# Title style definition
Style Нормоконтролёр
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gostnormokontroler
  ParSkip		0.0
  ItemSep		0
  TopSep		0
  BottomSep		0
  ParSep		0
  Align			Left
  AlignPossible		Left
  LeftMargin            MMMMMMMMMMMMM
  LabelType		Static
  LabelString   "Нормоконтролёр: "

  # standard font definition
  Font 
    Size		Normal
  EndFont
  LabelFont 
    Size		Normal
	Color		red
  EndFont
End

# Title style definition
Style Утвердил
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		gostutverdil
  ParSkip		0.0
  ItemSep		0
  TopSep		0
  BottomSep		0
  ParSep		0
  Align			Left
  AlignPossible		Left
  LeftMargin            MMMMMMMMMMMMM
  LabelType		Static
  LabelString   "Утвердил: "

  # standard font definition
  Font 
    Size		Normal
  EndFont
  LabelFont 
    Size		Normal
	Color		red
  EndFont
End

# Title style definition
Style Исполнители
  Margin		First_Dynamic
  LatexType		Command
  InTitle		1
  LatexName		gostispolnitel
  ParSkip		3
  ItemSep		0
  TopSep		0
  BottomSep		0
  ParSep		0
  Align			Left
  AlignPossible		Left
  LeftMargin            MMMMMMM
  LabelType		Static
  #LabelString   "Исполнитель: "

  # standard font definition
  Font 
    Size		Normal
  EndFont
  LabelFont 
    Size		Normal
	Color		red
  EndFont
End

# Author style definition
Style Author
  Margin		Static
  LatexType		Command
  InTitle		1
  LatexName		author
  LabelSep		xxx
  ParSkip		0.4
  TopSep		1.3
  BottomSep		0.7
  ParSep		0.7
  Align			Center
  AlignPossible		Center
  LabelType		No_Label

  # standard font definition
  Font 
    Size		Large
  EndFont

End

# Date style definition
#Style Дата_документа
Style ДатаДокумента
  Margin		Dynamic
  LatexType		Command
  InTitle		1
  LatexName		date
  LabelSep		xxx
  ParSkip		0.4
  TopSep		0.9
  BottomSep		0.5
  ParSep		1
  Align			Center
  AlignPossible		Center
  LabelType		No_Label


  # standard font definition
  Font 
    Size		Large
  EndFont

End

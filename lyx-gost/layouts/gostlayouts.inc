# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal AndrИ <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.

# GOST textclass (c) 2001 Vitaly Lipatov, Boris Balabanov
# Vitaly Lipatov (c) 2007
# Our parts licensed under GPL
# This include file contains various standard environments for lists,
# quotations, etc.


# Quotation style definition
Style Quotation
  Margin		Static
  LatexType		Environment
  LatexName		quotation
  NextNoIndent		1
  LeftMargin		MMM
  RightMargin		MMM
  ParIndent		MM
  ParSkip		0
  ItemSep		0
  TopSep		0.5
  BottomSep		0.5
  ParSep		0
  Align			Block
  AlignPossible		Block, Left, Right, Center
End

# Quote style definition
Style Quote
  Margin		Static
  LatexType		Environment
  LatexName		quote
  NextNoIndent		1
  LeftMargin		MMM
  RightMargin		MMM
  TopSep		0.5
  ParSep		0.5
  BottomSep		0.5
  Align			Block
  AlignPossible		Block, Left, Right, Center
  LabelType		No_Label
End

# Caption style definition
#Style Подпись_к_рисунку
Style ПодписьКРисунку
#Style Caption_for_figure
  Margin		First_Dynamic
  LatexType		Command
  LatexName		captionfigure
  NeedProtect		1
  LabelSep		xx
  ParSkip		0.4
  TopSep		0.5
  Align			Center
  AlignPossible		Center
  LabelType		Sensitive
  LabelString		Рисунок:

  # label font definition
  LabelFont 
    Series		Bold
  EndFont
End

# Caption style definition
Style Caption
  Margin		First_Dynamic
  LatexType		Command
  LatexName		caption
  NeedProtect		1
  LabelSep		xx
  ParSkip		0.4
  TopSep		0.5
  Align			Center
  AlignPossible		Center
  LabelType		Sensitive

  # label font definition
  LabelFont 
    Series		Bold
  EndFont
End

# Caption style definition
#Style Подпись_к_таблице
Style ПодписьКТаблице
  Margin		First_Dynamic
  LatexType		Command
  LatexName		captiontable
  NeedProtect		1
  LabelSep		xx
  ParSkip		0.4
  TopSep		0.5
  Align			Left
  AlignPossible		Left
  LabelType		Sensitive
  LabelString		Таблица:

  # label font definition
  LabelFont 
    Series		Bold
  EndFont
End

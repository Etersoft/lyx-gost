# GOST textclass (c) 2001 Vitaly Lipatov, Boris Balabanov
# Vitaly Lipatov (c) 2007
# Our parts licensed under GPL
# Cut & paste from various LyX layouts plus some major modifications
# This include file contains some numbered items for GOST

# Engost style definition
Style Пункт
  Margin		Dynamic
  LatexType		Item_Environment
  LatexName		engost
  NeedProtect		1
  NextNoIndent		0
  ParIndent			"MMMM"
  LeftMargin		""
  LabelSep		xx
  Align			Block
  AlignPossible		Block, Left

  LabelType			Counter
  LabelCounter		engoste
  LabelString       "@Subsubsection@.\arabic{engoste}"
  # TODO: Add \Azbuk instead Alph
  LabelStringAppendix "\Alph{section}.\arabic{subsection}.\arabic{subsubsection}.\arabic{engoste}"

  # standard font definition
  #Font 
  #  Series 		Bold
  #  Size		Normal
  #EndFont

End


# Ensubgost style definition
Style Подпункт
  Margin		Dynamic
  LatexType		Item_Environment
  LatexName		ensubgost
  NeedProtect		1
  NextNoIndent		0
  ParIndent		MMMMMMMMMMMMMM
#  LabelSep		xxx
  ParSkip		0.4
#  TopSep		0.9
#  BottomSep		0.5
#  ParSep		0.5
#  LeftMargin		MMMMMM
  Align			Block
  AlignPossible		Block, Left
  LabelType			Counter
  LabelCounter		ensubgoste
  LabelString       "@Пункт@.\arabic{ensubgoste}"
  LabelStringAppendix       "@Пункт@.\arabic{ensubgoste}"
#  LabelStringAppendix       "\Alph{section}.\arabic{subsubsection}.\arabic{ensubgoste}"

  # standard font definition
  Font 
    Series 		Medium
    Size		Normal
  EndFont

End


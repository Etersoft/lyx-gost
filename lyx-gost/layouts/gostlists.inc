# Standard textclass definition file. Taken from initial LyX source code
# Author : Matthias Ettrich <ettrich@informatik.uni-tuebingen.de>
# Transposed by Pascal AndrИ <andre@via.ecp.fr>
# Heavily modifed and enhanced by several developers.

# Cut & paste from various LyX layouts plus some major modifications
# GOST textclass (c) 2001 Vitaly Lipatov, Boris Balabanov
# Our parts licensed under GPL
# This include file contains various standard environments for lists.

# Itemize style definition
Style Перечисление
  Margin		First_Dynamic
  LatexType		Item_Environment
  LatexName		gostitemize
  NextNoIndent		0
  LeftMargin		""
  LabelSep		xx
  ItemSep		0.1
  TopSep		0.5
  BottomSep		0.7
#  ParSep		0.1
  Align			Block
  AlignPossible		Block, Left
  LabelType		Static
  LabelString		"    --"
  
  Preamble
  \newenvironment{gostitemize}%
    {\begin{list}{\labelitemi}{%
	\setlength{\itemindent}{\leftmargini}%
	  %\setlength{\itemindent}{\parindent}%
	  %\addtolength{\itemindent}{\labelsep}%
	  \setlength{\leftmargin}{0mm}%
	  %\setlength{\topsep}{1mm}%
	  }%
	  %\itemsep=-1mm%
	  %\addtolength{\itemindent}{5mm}%
	  %\listparindent=25mm%
	}%
    {\end{list}\par}
  EndPreamble

End

# Enumerate style definition
Style ПеречислениеНум
  Margin		Static
  LatexType		Item_Environment
  LatexName		gostenumerate
#  LatexName		enumerate
  NextNoIndent		0
  LeftMargin		MMNI
  LabelSep		xx
#  ParSkip		0.0
  ItemSep		0.1
  TopSep		0.5
  BottomSep		0.7
 # ParSep		0.1
  Align			Block
  AlignPossible		Block, Left
  LabelType		Counter_EnumI
  
  Preamble
    \renewcommand{\theenumi}{\asbuk{enumi}}
    \renewcommand{\theenumii}{\arabic{enumii}}
    \renewcommand\labelenumi{\theenumi)}
    \renewcommand\labelenumii{\theenumii)}   
  \newenvironment{gostenumerate}
    {\begin{enumerate}{}
	  %\itemsep=-1mm%
	  %\partopsep=-2mm%
	  %\parsep=40mm%
	  %\topsep=40mm%
	  %\parskip=40mm%
	  %\setlength{\itemindent}{\parindent}%
	  %\addtolength{\itemindent}{5mm}%
	  %\listparindent=25mm%
	  %\leftmargin=15mm
	}
    {\end{enumerate}\par}
  EndPreamble
  
End

# Description style definition
Style Description
  Margin		First_Dynamic
  LatexType		Item_environment
  LatexName		description
  NextNoIndent		0
  LeftMargin		MM
  LabelSep		xxx
  ParSkip		0.4
  ItemSep		0.2
  TopSep		0.7
  BottomSep		0.7
  ParSep		0.3
  Align			Block
  AlignPossible		Block, Left
  LabelType		Manual
  LabelString		MM

  # label font definition
  LabelFont 
    Series		Bold
  EndFont
End

# List style definition
Style List
  Margin		Manual
  LatexType		List_Environment
  LatexName		lyxlist
  NextNoindent		0
  LabelSep		xxx
  ParSkip		0.4
  TopSep		0.7
  BottomSep		0.7
  ParSep		0.5
  Align			Block
  AlignPossible		Block, Left
  LabelType		Manual
  LabelString		00.00.0000

  #define the environment lyxlist
  Preamble
  \newenvironment{lyxlist}[1]
    {\begin{list}{}
      {
	   %\itemsep=-1mm%
	   \settowidth{\labelwidth}{#1}
       \setlength{\leftmargin}{\labelwidth}
       \addtolength{\leftmargin}{\labelsep}
       \renewcommand{\makelabel}[1]{##1\hfil}}}
    {\end{list}\par}
  EndPreamble

End

# GOST textclass definition file.
# Based on Article textclass definition file for LyX, latex.ltx, article.cls
# and other files from /usr/share/texmf (tetex version)
# (c) 2001-2002 Boris Balabanov
# (c) 2001-2003 Vitaly Lipatov
# Our parts licensed under GPL
# $Id$


Preamble

	\usepackage{indentfirst} % �������� ������ � ������� ������
	\usepackage{multicol} % �����������������
	\usepackage{textcomp} % ���� ��������� ������
	\usepackage{floatflt}
	\usepackage{footnpag} % ������� ��� ������
	\usepackage{ifthen}
	\usepackage{mathtext} % ��������� ������������ ������� ����� � ��������
	\usepackage{babel} % ����� �����, � LyX 1.2.0 ���������� ��� ������ �����
	\usepackage{geometry}%��� ��������� ��������� ��������                                                           
	\usepackage{float}
	\usepackage{rotating}%�������� ����������
	\geometry{verbose,a4paper}%��������� �����
	\usepackage{graphicx}
	\usepackage{calc} %��� ����������� ��������� ��������
	\usepackage[bottom]{footmisc}  %��� ��������� ������ ������ ����� ��������
	% ����� ������� ������� �� �������� �� ����
	\sloppy

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% ��������� ������� ������� ������
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\setlength{\headheight}{0pt}
	\setlength{\headsep}{0pt}
	\setlength{\topmargin}{-1.0cm}
	\setlength{\textwidth}{16.3cm}
	\setlength{\textheight}{22.5cm}
	\setlength{\oddsidemargin}{0.5cm}
	\setlength{\evensidemargin}{0pt}
	\setlength{\marginparsep}{0pt}
	\setlength{\marginparpush}{0pt}
	\parindent=15mm  % �������� ������
	%\pargostzero=0mm
	\setlength{\leftmargini}{\parindent}
	\addtolength{\leftmargini}{5mm}


	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% ��������������� �������
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	%\addtocounter{secnumdepth}{-2}

	\ifnum \c@secnumdepth < 4
		\newcommand{\theengost}{\thesection.\@arabic\c@engost}%              
		\newcounter{engost}[section]
	\else                                                                         
    	\ifnum \c@secnumdepth < 5
			\newcommand{\theengost}{\thesubsection.\@arabic\c@engost}%
			\newcounter{engost}[subsection]
		\else                                                                       
			\ifnum \c@secnumdepth < 6
				\newcommand{\theengost}{\thesubsubsection.\@arabic\c@engost}%
				\newcounter{engost}[subsubsection]
			\else
				\ifnum \c@secnumdepth < 7
					\newcommand{\theengost}{\theparagraph.\@arabic\c@engost}%
					\newcounter{engost}[paragraph]
				\else
					\ifnum \c@secnumdepth < 8
						\newcommand{\theengost}{\thesubparagraph.\@arabic\c@engost}%
						\newcounter{engost}[subparagraph]
					\else
						\newcommand{\theengost}{\@arabic\c@engost}%
						\newcounter{engost}
					\fi
				\fi
        	\fi                                                                       
    	\fi                                                                         
    \fi 
	% ��������� ����� (engost) ��� ���������� ��������� �� ����
	\newenvironment{engost}%
	{%
		\renewcommand\item{%
			\par%
			\refstepcounter{engost}%
			\theengost
			%\arabic{section}.\arabic{subsection}.\arabic{engost}%
			\quad%
		}%
    }%

	\newcounter{ensubgost}[engost]	    			
	\renewcommand{\theensubgost}{\theengost.\arabic{ensubgost}}%              
	\newenvironment{ensubgost}
    {%
    	\renewcommand{\item}{%
		    \par%
		    \refstepcounter{ensubgost}%
		    \theensubgost%
		    \quad%
	    }%
    }%

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% ������ � ����� ��������
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\newcommand{\gostnewpage}{\newpage}
	
	% ������ ������������ � �������� �������
	\newcommand{\setgostnamesize}{\small}

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% ��������������� ���� ��������
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\renewcommand\section{%
		\renewcommand{\theengost}{\thesection.\@arabic\c@engost}
		\setcounter{engost}{0}
		\gostnewpage
		\@startsection {section}{1}{\parindent}%
			{-6.5ex \@plus -1ex \@minus -.2ex}%
			{2.3ex \@plus.2ex}%
			{\normalfont\Large\bfseries}}
	\renewcommand\subsection{%
		\renewcommand{\theengost}{\thesubsection.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{subsection}{2}{\parindent}%
			{-3.25ex\@plus -1ex \@minus -.2ex}%
			{1.5ex \@plus .2ex}%
			{\normalfont\large\bfseries}}
	\renewcommand\subsubsection{%
		\renewcommand{\theengost}{\thesubsubsection.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{subsubsection}{3}{\parindent}%
			{-3.25ex\@plus -1ex \@minus -.2ex}%
			{1.5ex \@plus .2ex}%
			{\normalfont\normalsize\bfseries}}
	\renewcommand\paragraph{%
		\renewcommand{\theengost}{\theparagraph.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{paragraph}{4}{\parindent}%
			{3.25ex \@plus1ex \@minus.2ex}%
			{-1em}%
			{\normalfont\normalsize\bfseries}}
	\renewcommand\subparagraph{%
		\renewcommand{\theengost}{\thesubparagraph.\@arabic\c@engost}
		\setcounter{engost}{0}
		\@startsection{subparagraph}{5}{\parindent}%
			{3.25ex \@plus1ex \@minus .2ex}%
			{-1em}%
			{\normalfont\normalsize\bfseries}}

	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% ��������� ����
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\def\gostgrifsoglasovano#1{\gdef\@gostgrifsoglasovano{#1}} 
	\def\gostgrifutverjdeno#1{\gdef\@gostgrifutverjdeno{#1}} 
	\def\gosttitleobject#1{\gdef\@gosttitleobject{#1}}
	\def\gosttitledocument#1{\gdef\@gosttitledocument{#1}} 
	\def\gostoboznacheniein#1 #2 {\gdef\@gostoboznacheniespec{#1}\gdef\@gostoboznacheniedok{#2}\gdef\@gostoboznachenie{#1#2}}
	\def\gostoboznachenie#1{\gostoboznacheniein #1 }
	\def\gosttitlecompany#1{\gdef\@gosttitlecompany{#1}} 
	\def\gostutverdil#1{\gdef\@gostutverdil{#1}}
	\def\gostnormokontroler#1{\gdef\@gostnormokontroler{#1}} 
	\def\gostrazrabotchik#1{\gdef\@gostrazrabotchik{#1}} 
	\def\gostproveril#1{\gdef\@gostproveril{#1}} 
	\def\gostispolnitel#1{\gdef\@gostispolnitel{#1}} 
  
 	\gosttitlecompany{}
	\gostnormokontroler{}
	\gostrazrabotchik{}
	\gostproveril{}
	\gostoboznachenie{}
	\gosttitledocument{}
	\gosttitleobject{~ }
	\gostgrifutverjdeno{}
	\gostgrifsoglasovano{}
	\gostutverdil{}
	\gostispolnitel{}

  
	%  ���������� ������� ������������ ���������� �����
	\renewcommand\maketitle{%
		\begin{titlepage}%
			\let\footnotesize\small
			\let\footnoterule\relax
			\let \footnote \thanks
			%  \null\vfil
			\begin{center}
				{\LARGE \@gosttitlecompany \par}%
				\vskip 1cm
			\end{center}
			\par%
			%{%\raggedleft%
			\begin{tabular}{l}%
				\ignorespaces                            
				\@gostgrifsoglasovano
			\end{tabular}                                                                
			\hfill
			\begin{tabular}{l}%
				\ignorespaces                            
				\@gostgrifutverjdeno
			\end{tabular}
			\vspace{1.4em}                                                               
			\par
			%}
			\vskip 60\p@
			\begin{center}%
				\vskip 3em%
				{\large%
				\lineskip 2cm%
				\addtolength{\parskip}{\baselineskip}
				%      \begin{tabular}[t]{c}%
				%        \@author
				%		\par
				\LARGE{\@gosttitleobject}
				\par
				\@gosttitledocument
				\par
				\@gostoboznachenie
				%      \end{tabular}
				\par
				}%
				\vfill
				\begin{flushleft}
					%\addtolength{\parskip}{\baselineskip}
					%�����������:
					%\par
					%\vskip 5pt
					%\hskip 1cm
					\parindent=1cm
					%\setlength{\baselineskip}{2\baselinestretch}
					\baselineskip=0.8cm
					\par
					%\begin{tabular}{l}%
					
						\@gostispolnitel
					%\end{tabular}
				\end{flushleft}
				\vfill
				\vfill
				{\large \@date \par}%
			\end{center}
	%		\par
	%  \
	%  \@thanks
	%  \vfil\null
	\end{titlepage}%
	\addtocounter{page}{1}
	\setcounter{footnote}{0}%
	\global\let\thanks\relax
	\global\let\maketitle\relax
	\global\let\@thanks\@empty
	\global\let\@author\@empty
	\global\let\@date\@empty
	%  \global\let\@gosttitlecompany\@empty
	\global\let\@gostgrifsoglasovano\@empty
	\global\let\@gostgrifutverjdeno\@empty
	%  \global\let\@gostoboznachenie\@empty
	%  \global\let\@gosttitleobject\@empty
	%  \global\let\@gosttitledocument\@empty
	\global\let\gostgrifsoglasovano\relax
	\global\let\gostgrifutverjdeno\relax
	\global\let\gostoboznachenie\relax
	\global\let\gosttitleobject\relax
	\global\let\gosttitledocument\relax
	\global\let\gosttitlecompany\relax
	\global\let\gostispolnitel\relax
	\global\let\author\relax
	\global\let\date\relax
	\global\let\and\relax
	}

	%%% ��������� ��� ������� �����
	\usepackage{eso-pic,graphicx}
	\newcommand\BackgroundPicture[2]{%
		\setlength{\unitlength}{1pt}%
		\put(0,\strip@pt\paperheight){%
		\parbox[t][\paperheight]{\paperwidth}{%
		\vfill 
		\centering\includegraphics[angle=#2]{#1}
		\vfill 
	}}} %

	\usepackage{lastpage}
	\usepackage{everyshi}
	% \renewcommand\thepage{\arabic{page} of \pageref{LastPage}}
	\usepackage{epsfig}
	\usepackage{psfrag}
	%\usepackage{calc}

	\newcounter{gostszv}
	\newcounter{gostlastpage}
	\newcounter{gostszvv}
	\newlength{\gostorigline}%
	\newlength{\gostadnomin}%
	\newsavebox{\newgostboxik}%

	% ��� ������ ������ � ���� � ���������� ������������ �����
	% 1,2 ���������� x,y ������ ������� ����, 3,4 ������� �������� ����
	% 5 ������������ 6 �����
	\def\spbox#1#2#3#4#5#6{%
		\put(#1,#2){%
			\setcounter{gostszv}{#3-#1}%
			\setcounter{gostszvv}{#4-#2}%
			\makebox(\value{gostszv},\value{gostszvv})[#5]{#6}%
		}%
	}

	% ������� �����, ���� �� �� ������� � ��������� box
	\def\spformedbox#1#2#3#4#5#6{%
		\setcounter{gostszv}{#3-#1}%
		\setcounter{gostszvv}{#4-#2}%
		\setlength{\gostadnomin}{#3pt - #1pt}%������ ����
		{%
			\sbox{\newgostboxik}{#6}%
			\settowidth{\gostorigline}{\usebox{\newgostboxik}}%
			\put(#1,#2){%
				\ifthenelse{\lengthtest{\gostorigline<\gostadnomin}}%
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{\usebox{\newgostboxik}}}%
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{\resizebox{\gostadnomin}{\height}{\usebox{\newgostboxik}}}}%
			}%
		}%
	}

	\def\spvertnormbox#1#2#3#4#5#6#7{%
		\setcounter{gostszv}{#3-#1}%
		\setcounter{gostszvv}{#4-#2}%
		\setlength{\gostadnomin}{#4pt - #2pt}%������ ��������� �����
		{%
			\sbox{\newgostboxik}{#6}%
			\settoheight{\gostorigline}{\usebox{\newgostboxik}}%
			\put(#1,#2){%
				\ifdim \gostorigline > \gostadnomin
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{\usebox{\newgostboxik}}}%
				\else
					{\makebox(\value{gostszv},\value{gostszvv})[#5]%
						{#7}}%
				\fi
			}%
		}%
	}

	% ����� ������ � ������������ ����
	\def\vspbox#1#2#3#4#5#6{%
		\put(#1,#2){%
			\setcounter{gostszv}{#3-#1}%
			\setcounter{gostszvv}{#4-#2}%
			\begin{sideways}%
				\makebox(\value{gostszv},\value{gostszvv})[#5]{#6}%
			\end{sideways}%
		}%
	}%

	%\def\two@digits#1{\ifnum#1<10 0\fi\number#1}

	% ���� � ������ �����
	\def\pathtosharedresource{/usr/share/lyx/clipart/}
	% ����� ������� gost_frame_compat ��� ������� ����������� �����,
	% ��� ��� ���������, ������� �� ����� �������� ������ � �������
	% ����
	\def\namegostframe{gost_frame}
	\newcommand\GostFrameCompatible{%
		\def\namegostframe{gost_frame_compat}%
	}
	% !!!!!!!
	% �������� ����� �������� ����������� �����
	\GostFrameCompatible
	\def\thegostpage{\thepage}
	\def\thegostlastpage{\pageref{LastPage}}
	\newcommand\NoPageNumbers{%
		\def\thegostpage{}%
		\def\thegostlastpage{}%
	}%
	%\NoPageNumbers


%\def\lastpage@putgostcounter{
%   \immediate\write\@auxout{\string
%   \setcounter{gostlastpage}{\value{page} + 2}%
%   }%
%   }

% � ����� ��������� ��������� ������ ��������
\AtEndDocument{%
\clearpage%
%\AddToShipoutPicture{\BackgroundPicture{/tmp/changelist.eps}{0}%
}%


	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	% ������ ����������. ��������� ����� �������. 
	% ���������� �������� � pt, ��������������� ����������� � ���������
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	\let\@oldoddfoot\@oddfoot
	\def\@oddfoot{%
		\unitlength=1pt
		%  \begin{picture}(0,0)(87,0)
		%  \begin{picture}(0,0)(100,2)
		%  \begin{picture}(0,0)(100,68)
		% ���������� 3 ����� - ����� �����
		% ���������� 4 ����� - ����� ����
		\ifthenelse{\equal{\namegostframe}{gost_frame}}%
			{\begin{picture}(0,0)(86,68)}%
			{\begin{picture}(0,0)(86,68)}%
		%
		% ������-�� �� oddfoot �� ���������� ��� ������ ��������
		\spbox{483}{15}{562}{22}{r}{{\tiny ������ A4}}
		\ifnum \thepage = 1
			\else
		\ifnum \thepage = 2
			% ������ ��������
			%\spbox{483}{15}{562}{22}{r}{{\tiny ������ A4}}
			\spbox{524}{67}{579}{79}{c}{\thegostlastpage}
			\spbox{481}{67}{522}{79}{c}{\thegostpage}
			\spformedbox{106}{81}{167}{93}{l}{\textsl{\small\@gostrazrabotchik}}
			\spformedbox{105}{67}{167}{80}{l}{\textsl{\small\@gostproveril}}
			\spformedbox{105}{39}{167}{51}{l}{\textsl{\small\@gostnormokontroler}}
			\spformedbox{105}{25}{167}{37}{l}{\textsl{\small\@gostutverdil}}
			\spbox{242}{96}{578}{136}{c}{\LARGE{\@gostoboznachenie}}
			\vspbox{38}{660}{202}{673}{c}{\normalsize\@gostoboznacheniespec}
			\spbox{245}{25}{430}{92}{c}
				{\parbox{60mm}{\centering\setgostnamesize{\@gosttitleobject} \\ \@gosttitledocument}}
		\else
			% ����������� ��������
			%\spbox{483}{15}{562}{22}{r}{{\tiny ������ A4}}
			\spbox{552}{25}{578}{45}{c}{\thegostpage}
			\spbox{242}{25}{549}{65}{c}{\LARGE{\@gostoboznachenie}}
			%\setcounter{gostszv}{\pageref{LastPage}}%
			%\setcounter{gostszv}{1}%
			%\def\thelastpage\\string\pageref{LastPage}
			%\ifnum  \thelastpage = 1
			%	ZZZZZZZZZZZZZ
			%\fi
			%\ifthenelse{\value{page} = \value{gostlastpage}}%
			%	{123-------------------------}%
			%	{ZZZZZZZZZZZZZ \thepage = \arabic{gostlastpage} = \pageref{LastPage} = \expandafter\@secondoftwo{LastPage} = \csname r@LastPage\endcsname ZZZZZZZZZZZZZ}%
		\fi
		\fi
		\end{picture}
	}
	%\def\@oddfoot{}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ����� ������  ������ �������� ��������� ��������� ���
%% ��� ������ �����
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\EveryShipout{%
  \ClearShipoutPicture%
  \ifnum \thepage = 1%
%��������� ������� �����
    \AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 2.eps}{0}}%
    \enlargethispage{-2.5cm}%
  \else%
%��������� ��������� ������
    \AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 3.eps}{0}}%
%    \AddToShipoutPicture{\BackgroundPicture{/tmp/changelist.eps}{0}}%
  \fi%
}
\let\@evenfoot\@oddfoot
\let\@evenhead\@oddhead
\AddToShipoutPicture{\BackgroundPicture{\pathtosharedresource \namegostframe 1.eps}{0}}
\setlength{\textheight}{24.7cm}
\enlargethispage{2.3cm}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% ��������� ���� �������� � �������� � ��������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\usepackage[center]{caption2}
\renewcommand{\captionlabeldelim}{~ ---}
%\renewcommand\captionmargin{0.2cm}
% ������� � �������
\addto\captionsrussian{%
  \def\figurename{{\cyr�������}}%
}
% ������� ��� ������ �������� ���������� ����
\newcommand{\captiontable}[1]{\caption{#1}}
\newcommand{\captionfigure}[1]{\caption{#1}}
%\defcaptionstyle{#1}{#2}%

%\newcommand{\@ldtable}{}
%\let\@ldtable\table
%\renewcommand{\table}{%
%	\setlength{\@tempdima}{\abovecaptionskip}%
%	\setlength{\abovecaptionskip}{\belowcaptionskip}%
%	\setlength{\belowcaptionskip}{\@tempdima}%
%	\@ldtable}%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ��������� ������ ������� � ������ �� ���
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  \def\@eqnnum{{\normalfont \normalcolor \theequation}}
  \renewcommand{\theequation}{(\arabic{equation})}%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ������������� ����������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand\tableofcontents{%
\begin{center}
  {
  \Large\bf\contentsname
  }
\end{center}
    \@starttoc{toc}%
    \newpage
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% ��� ������� � ����������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  \renewcommand{\l@subsection}{\@dottedtocline{2}{0em}{2.3em}}
  \renewcommand{\l@subsubsection}{\@dottedtocline{3}{0em}{3em}}

\renewcommand*\l@section[2]{%
  \ifnum \c@tocdepth >\z@
    \addpenalty\@secpenalty
    \addvspace{1.0em \@plus\p@}%
%    \setlength\@tempdima{1.5em}%
    % ������ ���� ��� ������ ��������
    %\renewcommand\@pnumwidth{5.55em}
    \begingroup
%      \leftskip 0 em\relax \rightskip \@tocrmarg \parfillskip -\rightskip
%      \parindent 0em\relax\@afterindenttrue
%      \interlinepenalty\@M
%      \leavevmode
    % ������ ������ ������ � ����������
      \@tempdima 1.7 em\relax

      \parindent \z@ \rightskip \@pnumwidth
      \parfillskip -\@pnumwidth
%      \parfillskip -\rightskip
      \leavevmode %\bfseries
%      \advance\leftskip\@tempdima \hskip -\leftskip
      \advance\leftskip \@tempdima \null\nobreak\hskip -\leftskip
%    ������ ������� ����� � �������� ������ ����������
     {\bfseries {#1}\nobreak }%
     \leaders\hbox{%
	 	$\m@th
        \mkern \@dotsep mu\hbox{.}\mkern \@dotsep%
        mu$}\hfill%
     \nobreak%
%    ����� ��������� ����� ��������
%     \hb@xt@\@pnumwidth{\hss #2}\par
     \hb@xt@\@pnumwidth{\hfil\normalfont \normalcolor #2}%
     \par%
%
%      
%      #1\nobreak\hfil \nobreak\hb@xt@\@pnumwidth{\hss #2}\par
    \endgroup
  \fi}

%  \renewcommand*{\l@section}{\@dottedtocline{1}{0em}{2.3em}}
  


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%���� � ������������ (�������������� ������)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand{\labelitemi}{\normalfont\bfseries{--}}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% �������, ����������� ������������� �������� �������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% �������� �� ������������� ������ ������� � ������
\newcommand{\sectname}[2]{%
		\csname the#1\endcsname\quad
}

% �������� �� ������������� ������ ������� � ����������
\newcommand{\sectnameintoc}[2]{%
		\protect\numberline{\csname the#1\endcsname}%
}

% ������� ����� ������� ������� � ��� ���������
\newcommand{\sectdop}[1]{%
	\raggedright%
	\interlinepenalty \@M%
}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% ����� �� latex.ltx � ���������� ��� ���� ���������� %%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\def\@sect#1#2#3#4#5#6[#7]#8{%
  \ifnum #2>\c@secnumdepth
    \let\@svsec\@empty
  \else
  % ���� ������� ��������� ��������
    \refstepcounter{#1}%
	% ����� ��� @seccntformat
    \protected@edef\@svsec{\sectname{#1}{#2}\relax}%
  \fi
  \@tempskipa #5\relax
  \ifdim \@tempskipa>\z@
    \begingroup
      #6{%
	  	
	    % ��������� ����� �������
        \@hangfrom{\hskip #3\relax\@svsec}%
	% ��������� �������� �������
	\sectdop{#2}#8
	\@@par}%
    \endgroup
    \csname #1mark\endcsname{#7}%
    \ifnum #2>\c@tocdepth \else
      \addcontentsline{toc}{#1}{%
        \ifnum #2>\c@secnumdepth \else
%       \ifnum #2>\c@tocdepth \else
          \sectnameintoc{#1}{#2}%
        \fi
        #7}%
    \fi
  \else
    \def\@svsechd{%
	\hyphenation{#8}%
      #6{\hskip #3\relax
      \@svsec #8}%
      \csname #1mark\endcsname{#7}%
      \addcontentsline{toc}{#1}{%
        \ifnum #2>\c@secnumdepth \else
          \protect\numberline{\csname the#1\endcsname}%
        \fi
        #7}}%
  \fi
  \@xsect{#5}}
\def\@xsect#1{%
  \@tempskipa #1\relax
  \ifdim \@tempskipa>\z@
    \par \nobreak
    \vskip \@tempskipa
    \@afterheading
  \else
    \@nobreakfalse
    \global\@noskipsectrue
    \everypar{%
      \if@noskipsec
        \global\@noskipsecfalse
       {\setbox\z@\lastbox}%
        \clubpenalty\@M
        \begingroup \@svsechd \endgroup
        \unskip
        \@tempskipa #1\relax
        \hskip -\@tempskipa
      \else
        \clubpenalty \@clubpenalty
        \everypar{}%
      \fi}%
  \fi
  \ignorespaces}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% ����� �� bk12.clo � ���������� ��� ���� ���������� %%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% ��������� ��� 1-�� ������ ������
\def\@listi{\leftmargin\leftmargini
%            \parsep 5\p@  \@plus2.5\p@ \@minus\p@
            \parsep 0\p@  \@plus2.5\p@ \@minus\p@
            \topsep 3\p@ \@plus3\p@   \@minus2\p@
%				\topsep \z@
%            \itemsep1\p@  \@plus2.5\p@ \@minus\p@}
            \itemsep 1\p@}
\let\@listI\@listi
\@listi
% ��������� ��� 2-�� ������ ������
\def\@listii {\leftmargin\leftmarginii
              \labelwidth\leftmarginii
              \advance\labelwidth-\labelsep
              \topsep    1\p@   \@plus2.5\p@ \@minus\p@
%				\topsep \z@
              \parsep    1\p@ \@plus\p@    \@minus\p@
              \itemsep   \parsep}
% ��������� ��� 3-�� ������ ������ (� ���� �� ������������)
\def\@listiii{\leftmargin\leftmarginiii
              \labelwidth\leftmarginiii
              \advance\labelwidth-\labelsep
%              \topsep    2.5\p@\@plus\p@\@minus\p@
				\topsep \z@
              \parsep    \z@
              \partopsep \p@ \@plus\z@ \@minus\p@
              \itemsep   \topsep}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%����������� ��������� � ���������� ����������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\renewcommand\appendix{\par

%\addtocounter{tocdepth}{-1}
\setcounter{tocdepth}{1}

  \renewcommand{\section}{
    \renewcommand{\theengost}{\thesection.\@arabic\c@engost}
    \setcounter{engost}{0}
    \@startsection{section}
     {1}
     {0mm}
     {-\baselineskip}
     {\baselineskip}
     {\newpage\Large\bf}}%


   \addtocontents{toc}{\vskip 12pt }

  \setcounter{section}{0}%
  \setcounter{subsection}{0}%

% �������� �� ������������� �������� ������� � ������
\renewcommand{\sectname}[2]{%
	\ifnum ##2 > 1
		\csname the##1\endcsname\quad
	\else
		%\appendixname\ \csname the##1\endcsname
		\protect\makebox[\textwidth]{\appendixname\ \csname the##1\endcsname}%

	\fi
}

% �������� �� ������������� �������� ������� � ����������
\renewcommand{\sectnameintoc}[2]{%
	\ifnum ##2 > 1
		\protect\numberline{\csname the##1\endcsname}%
	\else
		\protect\appendixname\ \numberline{\csname the##1\endcsname}
	\fi
}

% �������� �� ����������� �������� ������� �� ������ ������ � ����������
\renewcommand{\sectdop}[1]{%
	\ifnum ##1 > 1
		\raggedright%
	\else
		\centering%
		{\\\raisebox{3pt}{\em\normalsize(������������)}}\\
	\fi
}

  \renewcommand{\thesection}{\GostAsbuk{section}}%

% ��������� �������� � ��������� ������ ����������
  \@addtoreset{figure}{section}%                                                   
  \renewcommand{\thefigure}{\thesection.\arabic{figure}}%
  
% ��������� ������ � ��������� ������ ����������
  \@addtoreset{table}{section}%                                                   
  \renewcommand{\thetable}{\thesection.\arabic{table}}%
  
% ��������� ������ � ��������� ������ ����������
  \@addtoreset{equation}{section}%                                                   
  \renewcommand{\theequation}{(\thesection.\arabic{equation})}%
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%������ �� �������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 \renewcommand\thefootnote{\@arabic\c@footnote)}%   

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%���������� ������������� ������� ���� �� �������� 
%��� ��������� ����������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
\def\GostAsbuk#1{\expandafter\@GostAsbuk\csname c@#1\endcsname}                         
\def\@GostAsbuk#1{\ifcase#1\or                                                      
\CYRA\or\CYRB\or\CYRV\or\CYRG\or\CYRD\or\CYRE\or\CYRZH\or                     
\CYRI\or\CYRK\or\CYRL\or\CYRM\or\CYRN\or                      
\CYRP\or\CYRR\or\CYRS\or\CYRT\or\CYRU\or\CYRF\or\CYRH\or
\CYRC\or\CYRSH\or\CYRSHCH\or\CYREREV\or\CYRYU\or                     
\CYRYA\else\@ctrerr\fi}                                                       


% ��� ������������ ������� ������
\usepackage{longtable}
\LTleft=\z@
\LTright=\fill

\def\LT@makecaption#1#2#3{%                                                     
  \LT@mcol\LT@cols l{\hbox to\z@{\parbox[t]\LTcapwidth{%                    
      \sbox\@tempboxa{#1{#2\captionlabeldelim{} }#3}%                                                
          {\box\@tempboxa\hfil}%                                 
          \endgraf}%                                               
    \hss}}} 

\newcommand{\rem}[1]{}



\def\NoFrames{
\ClearShipoutPicture
\renewcommand\BackgroundPicture[2]{}
\let\@oddfoot\@oldoddfoot
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%% ����� ����� ��������� %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

EndPreamble

%define ENC1 koi8-r
%define ENC2 cp1251

Name: lyx-gost
Version: 1.3.4
Release: alt1

Summary: The GOST class files for LyX in koi8-r encoding
Summary(ru_RU.KOI8-R): Класс текста GOST для LyX в кодировке koi8-r
License: GPL
Group: Office
URL: http://www.etersoft.ru/content/category/9/80/63/

Packager: Vitaly Lipatov <lav@altlinux.ru>

Source: %name-%version.tar.bz2

BuildArchitectures: noarch
BuildPreReq: iconv
PreReq: lyx >= 1.3.0

%description
The %name package contains the LyX/LaTeX class for preparing documents
according to Russian GOST's demands.

%description -l ru_RU.KOI8-R
Пакет %name содержит класс для LyX/LaTeX, предназначенный для
подготовки технической текстовой документации в соответствии
с ГОСТ 2.105-95 (с рамками и основными надписями).

%package %ENC1
Summary: The GOST class files for LyX in koi8-r encoding
Summary(ru_RU.KOI8-R): Класс текста GOST для LyX в кодировке koi8-r
Group: Office

Provides: lyx-gost
Conflicts: lyx-gost-cp1251
Obsoletes: lyx-gost


%description %ENC1
The %name package contains the LyX/LaTeX class for preparing documents
according to Russian GOST's demands.

%description %ENC1 -l ru_RU.KOI8-R
Пакет %name содержит класс для LyX/LaTeX, предназначенный для
подготовки технической текстовой документации в соответствии
с ГОСТ 2.105-95 (с рамками и основными надписями).

%package %ENC2
Summary: The GOST class files for LyX in cp1251 encoding
Summary(ru_RU.KOI8-R): Класс текста GOST для LyX в кодировке cp1251
Group: Office

Provides: lyx-gost
Conflicts: lyx-gost-koi8-r
Obsoletes: lyx-gost

%description %ENC2
The %name package contains the LyX/LaTeX class for preparing documents
according to Russian GOST's demands.

%description %ENC2 -l ru_RU.KOI8-R
Пакет %name содержит класс для LyX/LaTeX, предназначенный для
подготовки технической текстовой документации в соответствии
с ГОСТ 2.105-95 (с рамками и основными надписями).


%prep
%setup -q

%install

mkdir -p $RPM_BUILD_ROOT%_datadir/lyx/{layouts,templates,clipart}

# Перекодируем исходные файлы в две целевых кодировки
# Обещаю избавиться от этого рано или поздно :)

for TARENC in %ENC1 %ENC2; do

#	for f in layouts/*.layout; do
#		iconv -f %ENC1 -t $TARENC "$f" | sed -e "s/.inc/-$TARENC.inc/g" >"$RPM_BUILD_ROOT/%_datadir/lyx/layouts/`basename $f .layout`-$TARENC.layout"
#	done

	for f in layouts/*.inc; do
		iconv -f %ENC1 -t $TARENC "$f" >"$RPM_BUILD_ROOT/%_datadir/lyx/layouts/`basename $f .inc`-$TARENC.inc"
	done
	
	for f in templates/*.lyx; do
		iconv -f %ENC1 -t $TARENC "$f" | sed -e "s/koi8-r/$TARENC/g" >"$RPM_BUILD_ROOT/%_datadir/lyx/templates/`basename $f .lyx`-$TARENC.lyx"
	done

	mkdir -p $RPM_BUILD_ROOT%_datadir/doc/%name-$TARENC
	cd doc
	for f in *;	do
		iconv -f %ENC1 -t $TARENC <"$f" >"$RPM_BUILD_ROOT/%_datadir/doc/%name-$TARENC/$f"
	done
	cd -
done

for i in layouts/*.layout clipart/*; do
	install -D -m644 $i ${RPM_BUILD_ROOT}/%_datadir/lyx/$i
done

%post %ENC1
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%post %ENC2
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%preun

%postun %ENC1
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%postun %ENC2
echo "Configuring LyX for your system..."
cd %prefix/share/lyx
./configure --srcdir

%files %ENC1
%doc %_datadir/doc/%name-%ENC1
%_datadir/lyx/layouts/*-%ENC1.inc
%_datadir/lyx/layouts/gost.layout
%_datadir/lyx/clipart/*
%_datadir/lyx/templates/*-%ENC1.lyx


%files %ENC2
%doc %_datadir/doc/%name-%ENC2
%_datadir/lyx/layouts/*-%ENC2.inc
%_datadir/lyx/layouts/gost.layout
%_datadir/lyx/clipart/*
%_datadir/lyx/templates/*-%ENC2.lyx


%changelog
* Fri Jun 18 2004 Vitaly Lipatov <lav@altlinux.ru> 1.3.4-alt1
- fix bug with formulae
- fix URL
- tested with LyX 1.3.4

* Tue May 13 2003 Vitaly Lipatov <lav@altlinux.ru> 1.3.1-alt2
- fixed encoding for docs in cp1251
- fixed name of docs dir

* Mon Mar 31 2003 Vitaly Lipatov <lav@altlinux.ru> 1.3.1-alt1
- updated for LyX 1.3.1
- new version of lyx-gost (see ChangeLog)

* Wed Dec 04 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt5
- corrected for tetex-2.0
- cleanup spec
- tested with LyX 1.2.1

* Mon Nov 11 2002 Stanislav Ievlev <inger@altlinux.ru> 1.2-alt4
- rebuild

* Sat Jul 06 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt3
- normalize code of textclass and gost frames
- packages for both encoding (koi8-r & cp1251)

* Fri Jun 14 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt2
- back to single source package for two destination
- update for LyX 1.2.0
- doc2lyx convertor removed
- add noarch option

* Sun Apr 14 2002 Vitaly Lipatov <lav@altlinux.ru> 1.2-alt1
- new version
- split in two package

* Tue Dec 22 2001 23:01:01 Vitaly Lipatov <lav@altlinux.ru> 1.1-alt1
- russian description charset fixed
- add new template delop.lyx
- new version of class GOST
- russian documentation for LyX moved to lyx-rusdoc

* Tue Dec 11 2001 11:19:09 Vitaly Lipatov <vitlav@mail.ru> 1.0-alt1
- first version

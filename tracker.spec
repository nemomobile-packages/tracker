# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.26
# 

Name:       tracker

# >> macros
%define enable_demo 0
# << macros

Summary:    An object database, tag/metadata database, search tool and indexer
Version:    0.14.4
Release:    1
Group:      Data Management/Content Framework
License:    GPLv2+
URL:        http://ftp.gnome.org/pub/GNOME/sources/tracker/0.10/
Source0:    http://ftp.gnome.org/pub/GNOME/sources/%{name}/0.14/%{name}-%{version}.tar.xz
Source1:    tracker-rpmlintrc
Source2:    tracker-store.service
Source3:    tracker-miner-fs.service
Source100:  tracker.yaml
Patch0:     0001-Tracker-extract-Parse-the-video-filename-to-obtain-e.patch
Patch1:     0002-Fix-missing-gobject-introspection-checks.patch
Patch2:     0003-tracker-0.10.37-fix-linking-with-newer-toolchain.patch
Patch3:     0004-tracker-0.10.37-fix-linking-with-newer-glib.patch
Patch4:     0005-Remove-tracker-tests.aegis-from-config_SCRIPTS-if-ma.patch
Patch5:     0006-tracker-tests-do-not-su-meego.patch
Patch6:     0007-tracker-tests-fix-undefined-function-call.patch
Patch7:     0008-tracker-tests-synchronous-terminate-pre-step.patch
Patch8:     0009-tracker-tests-increase-timeout.patch
Patch9:     0010-tracker-tests-fix-helper-starting-order.patch
Patch10:     0011-tracker-tests-make-400-extractor-work-with-testrunne.patch
Patch11:     0012-tracker-tests-allow-reuse-graph-updated-signal-handl.patch
Patch12:     0013-tracker-forget-removed-files.patch
Patch13:     0014-tracker-tests-310-fts-indexing-use-graph-updated-sig.patch
Patch14:     0015-tracker-tests-501-writeback-details-fix-invalid-meta.patch
Patch15:     0016-tracker-miner-fs-deal-with-data-inserted-by-other-ap.patch
Patch16:     0017-tracker-tests-400-extractor-skip-unsupported-file-ty.patch
Patch17:     0018-tracker-tests-exclude-200-backup-restore.patch
Patch18:     0019-tracker-disable-userguide-and-applications-miners.patch
Requires:   gst-plugins-base >= 0.10
Requires:   unzip
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(dbus-glib-1) >= 0.60
BuildRequires:  pkgconfig(enca)
BuildRequires:  pkgconfig(exempi-2.0)
BuildRequires:  pkgconfig(gconf-2.0)
BuildRequires:  pkgconfig(gee-1.0)
BuildRequires:  pkgconfig(glib-2.0) >= 2.26.0
BuildRequires:  pkgconfig(gmime-2.6)
BuildRequires:  pkgconfig(gstreamer-0.10)
BuildRequires:  pkgconfig(gstreamer-plugins-base-0.10)
BuildRequires:  pkgconfig(icu-uc)
BuildRequires:  pkgconfig(id3tag)
BuildRequires:  pkgconfig(libexif)
BuildRequires:  pkgconfig(libgsf-1)
BuildRequires:  pkgconfig(libiptcdata)
BuildRequires:  pkgconfig(libpng)
BuildRequires:  pkgconfig(libxml-2.0)
BuildRequires:  pkgconfig(ossp-uuid)
BuildRequires:  pkgconfig(poppler-glib)
BuildRequires:  pkgconfig(sqlite3) >= 3.7
BuildRequires:  pkgconfig(taglib)
BuildRequires:  pkgconfig(totem-plparser)
BuildRequires:  pkgconfig(uuid)
BuildRequires:  pkgconfig(libvala-0.16)
BuildRequires:  pkgconfig(vorbis)
BuildRequires:  pkgconfig(zlib)
BuildRequires:  pkgconfig(QtGui)
BuildRequires:  gettext
BuildRequires:  giflib-devel
BuildRequires:  intltool
BuildRequires:  libjpeg-devel
BuildRequires:  libtiff-devel >= 3.8.2
BuildRequires:  perl-XML-Parser
BuildRequires:  pygobject2
BuildRequires:  python >= 2.6
BuildRequires:  qt-devel
BuildRequires:  dbus-python
BuildRequires:  fdupes

%description
Tracker is a powerful desktop-neutral first class object database,
tag/metadata database, search tool and indexer.

It consists of a common object database that allows entities to have an
almost infinte number of properties, metadata (both embedded/harvested as
well as user definable), a comprehensive database of keywords/tags and
links to other entities.

It provides additional features for file based objects including context
linking and audit trails for a file object.

It has the ability to index, store, harvest metadata. retrieve and search
all types of files and other first class objects


%package tests
Summary:    Tests for tracker
Group:      System/X11
Requires:   %{name} = %{version}-%{release}
Requires:   dbus-python
Requires:   pygobject2
Requires:   python >= 2.6

%description tests
Functional tests for tracker to be run once tracker is installed in
the final environment.


%package utils
Summary:    Tracker command line applications to lookup data
Group:      Development/Tools
Requires:   %{name} = %{version}-%{release}

%description utils
Tracker command line applications to lookup data
Included utilities for Tracker are as follows
 tracker-import      Import TTL files.
 tracker-info        Display all information known about an entity.
 tracker-search      Search for entites (files, folders, videos, etc)
 tracker-sparql      Run a SPARQL query against the databases.
 tracker-stats       Get statistics on how many entities are indexed.
 tracker-tag         Add, remove, list tags for entities.


%package devel
Summary:    Development files for %{name}
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
Development files for %{name}.

%prep
%setup -q -n %{name}-%{version}

# 0001-Tracker-extract-Parse-the-video-filename-to-obtain-e.patch
%patch0 -p1
# 0002-Fix-missing-gobject-introspection-checks.patch
%patch1 -p1
# 0003-tracker-0.10.37-fix-linking-with-newer-toolchain.patch
%patch2 -p1
# 0004-tracker-0.10.37-fix-linking-with-newer-glib.patch
%patch3 -p1
# 0005-Remove-tracker-tests.aegis-from-config_SCRIPTS-if-ma.patch
%patch4 -p1
# 0006-tracker-tests-do-not-su-meego.patch
%patch5 -p1
# 0007-tracker-tests-fix-undefined-function-call.patch
%patch6 -p1
# 0008-tracker-tests-synchronous-terminate-pre-step.patch
%patch7 -p1
# 0009-tracker-tests-increase-timeout.patch
%patch8 -p1
# 0010-tracker-tests-fix-helper-starting-order.patch
%patch9 -p1
# 0011-tracker-tests-make-400-extractor-work-with-testrunne.patch
%patch10 -p1
# 0012-tracker-tests-allow-reuse-graph-updated-signal-handl.patch
%patch11 -p1
# 0013-tracker-forget-removed-files.patch
%patch12 -p1
# 0014-tracker-tests-310-fts-indexing-use-graph-updated-sig.patch
%patch13 -p1
# 0015-tracker-tests-501-writeback-details-fix-invalid-meta.patch
%patch14 -p1
# 0016-tracker-miner-fs-deal-with-data-inserted-by-other-ap.patch
%patch15 -p1
# 0017-tracker-tests-400-extractor-skip-unsupported-file-ty.patch
%patch16 -p1
# 0018-tracker-tests-exclude-200-backup-restore.patch
%patch17 -p1
# 0019-tracker-disable-userguide-and-applications-miners.patch
%patch18 -p1
# >> setup
# << setup

%build
# >> build pre
export AUTOPOINT="intltoolize --automake --copy"
chmod +x tests/functional-tests/create-tests-xml.py
# << build pre

%reconfigure --disable-static \
    --with-compile-warnings=no \
    --disable-tracker-preferences \
    --disable-tracker-search-bar \
    --disable-tracker-explorer \
    --enable-unit-tests \
    --enable-functional-tests \
    --disable-miner-evolution \
    --disable-miner-flickr \
    --disable-miner-rss \
    --enable-maemo \
    --enable-guarantee-metadata \
    --with-unicode-support=libicu \
    --disable-tracker-needle \
    --enable-libvorbis \
    --enable-tracker-fts \
    --enable-qt

make %{?jobs:-j%jobs}

# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
# << install pre
%make_install
mkdir -p %{buildroot}%{_libdir}/systemd/user/
cp -a %{SOURCE2} %{buildroot}%{_libdir}/systemd/user/
mkdir -p %{buildroot}%{_libdir}/systemd/user/
cp -a %{SOURCE3} %{buildroot}%{_libdir}/systemd/user/


# >> install post
rm -rf %{buildroot}/%{_datadir}/icons/hicolor/
rm -rf %{buildroot}/%{_datadir}/gtk-doc
# << install post

%find_lang %{name}

%fdupes  %{buildroot}/%{_datadir}/

%post
/sbin/ldconfig
# >> post
glib-compile-schemas   /usr/share/glib-2.0/schemas/
# << post

%postun
/sbin/ldconfig
# >> postun
glib-compile-schemas   /usr/share/glib-2.0/schemas/
# << postun

%files -f %{name}.lang
%defattr(-,root,root,-)
# >> files
%defattr(-, root, root, -)
%{_bindir}/tracker-control
%{_datadir}/dbus-1/services/*
%{_datadir}/man/man1/*
%{_datadir}/tracker/*.xml
%{_datadir}/tracker/languages/*
%{_datadir}/tracker/miners/*
%{_datadir}/tracker/ontologies/*
%{_datadir}/vala/vapi/*
%{_datadir}/tracker/extract-rules/*
%{_datadir}/glib-2.0/schemas/*.xml
%{_libdir}/libtracker-extract-*.so*
%{_libdir}/libtracker-miner-*.so*
%{_libdir}/libtracker-sparql-*.so*
%{_libdir}/tracker-*/*.so*
%{_libdir}/tracker-*/extract-modules/*.so*
%{_libdir}/tracker-*/writeback-modules/*.so*
%{_libexecdir}/tracker-extract
%{_libexecdir}/tracker-miner-fs
%{_libexecdir}/tracker-store
%{_libexecdir}/tracker-writeback
%config %{_sysconfdir}/xdg/autostart/tracker-miner-fs.desktop
%config %{_sysconfdir}/xdg/autostart/tracker-store.desktop
%{_libdir}/systemd/user/tracker-miner-fs.service
%{_libdir}/systemd/user/tracker-store.service
# << files

%files tests
%defattr(-,root,root,-)
# >> files tests
%{_datadir}/tracker-tests/*
%{_sysconfdir}/dconf/profile/trackertest
# << files tests

%files utils
%defattr(-,root,root,-)
# >> files utils
%{_bindir}/tracker-import
%{_bindir}/tracker-info
%{_bindir}/tracker-search
%{_bindir}/tracker-sparql
%{_bindir}/tracker-stats
%{_bindir}/tracker-tag
# << files utils

%files devel
%defattr(-,root,root,-)
# >> files devel
%{_includedir}/tracker-*/libtracker-extract/*.h
%{_includedir}/tracker-*/libtracker-miner/*.h
%{_includedir}/tracker-*/libtracker-sparql/*.h
%{_libdir}/pkgconfig/tracker-*.pc
# << files devel

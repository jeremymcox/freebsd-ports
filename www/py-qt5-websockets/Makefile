# $FreeBSD$

PORTNAME=	websockets
CATEGORIES=	www net devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebSockets module

CONFIGURE_ARGS=	--enable QtWebSockets
PYQT_DIST=	yes

USES=		python:3.5+ pyqt:5 qt:5
USE_PYQT=	sip_build core_run 
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core qmake_build network websockets

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtNetwork API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5/QtWebSockets.so

.include <bsd.port.mk>

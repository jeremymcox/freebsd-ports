# $FreeBSD$

PORTNAME=	molsketch
DISTVERSION=	0.7.0
DISTVERSIONSUFFIX=	-src
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/Molsketch/Oxygen%20${DISTVERSION}/
DISTNAME=	Molsketch-${DISTVERSIONFULL}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	2D molecule editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libopenbabel.so:science/openbabel

USES=		cmake compiler:c++11-lang desktop-file-utils localbase:ldflags \
		pkgconfig qt:5 shared-mime-info
USE_QT=		core gui network printsupport svg widgets buildtools_build qmake_build
USE_LDCONFIG=	${PREFIX}/lib/molsketch

CMAKE_ARGS=	-DMSK_PREFIX:STRING=${PREFIX}

WRKSRC=		${WRKDIR}/Molsketch-${DISTVERSION}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>

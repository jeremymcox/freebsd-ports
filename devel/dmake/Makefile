# Created by: nils@guru.ims.uni-stuttgart.de
# $FreeBSD$

PORTNAME=	dmake
PORTVERSION=	4.13.1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	office@FreeBSD.org
COMMENT=	Another hyper make utility

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/readme/license.txt

USES=		autoreconf

USE_GITHUB=	yes
GH_ACCOUNT=	jimjag
GH_TAGNAME=	v${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datarootdir=${DATADIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/dmake.tf ${STAGEDIR}${PREFIX}/man/man1/dmake.1

.include <bsd.port.mk>

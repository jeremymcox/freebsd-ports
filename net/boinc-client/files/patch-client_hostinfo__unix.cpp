--- client/hostinfo_unix.cpp.orig	2018-01-14 04:07:52.000000000 -0600
+++ client/hostinfo_unix.cpp	2018-11-11 21:32:22.082936000 -0600
@@ -164,7 +164,9 @@
 // The following is intended to be true both on Linux
 // and Debian GNU/kFreeBSD (see trac #521)
 //
-#define LINUX_LIKE_SYSTEM (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)) && !defined(__HAIKU__)
+#if (defined(__linux__) || defined(__GNU__) || defined(__GLIBC__) || defined (__freebsd__)) && !defined(__HAIKU__) 
+#define LINUX_LIKE_SYSTEM 1
+#endif
 
 // Returns the offset between LOCAL STANDARD TIME and UTC.
 // LOCAL_STANDARD_TIME = UTC_TIME + get_timezone().
@@ -722,10 +724,10 @@
 
 void use_cpuid(HOST_INFO& host) {
     u_int p[4];
-    int hasMMX, hasSSE, hasSSE2, hasSSE3, has3DNow, has3DNowExt;
+    int hasMMX, hasSSE, hasSSE2, hasSSE3, has3DNow, has3DNowExt, hasAVX, hasFMA;
     char capabilities[256];
 
-    hasMMX = hasSSE = hasSSE2 = hasSSE3 = has3DNow = has3DNowExt = 0;
+    hasMMX = hasSSE = hasSSE2 = hasSSE3 = has3DNow = has3DNowExt = hasAVX = hasFMA = 0;
     do_cpuid(0x0, p);
 
     if (p[0] >= 0x1) {
@@ -736,6 +738,8 @@
         hasSSE  = (p[3] & (1 << 25 )) >> 25; // 0x2000000
         hasSSE2 = (p[3] & (1 << 26 )) >> 26; // 0x4000000
         hasSSE3 = (p[2] & (1 << 0 )) >> 0;
+        hasAVX  = (p[2] & (1 << 28)) >> 28;
+        hasFMA  = (p[2] & (1 << 12)) >> 12;
     }
 
     do_cpuid(0x80000000, p);
@@ -753,6 +757,8 @@
     if (has3DNow) safe_strcat(capabilities, "3dnow ");
     if (has3DNowExt) safe_strcat(capabilities, "3dnowext ");
     if (hasMMX) safe_strcat(capabilities, "mmx ");
+    if (hasAVX) safe_strcat(capabilities, "avx ");
+    if (hasFMA) safe_strcat(capabilities, "fma ");
     strip_whitespace(capabilities);
     char buf[1024];
     snprintf(buf, sizeof(buf), "%s [] [%s]",

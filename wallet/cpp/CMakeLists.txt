cmake_minimum_required(VERSION 3.6.0)
add_library(scrypt SHARED scrypt_jni.c crypto_scrypt-nosse.c sha256.c)
add_library(x15 SHARED blake.c bmw.c cubehash.c echo.c fugue.c groestl.c hamsi.c hashblock.cpp jh.c keccak.c luffa.c shabal.c shavite.c simd.c skein.c whirlpool.c)
include_directories(.)

/**
 * Created by Hash Engineering on 4/24/14 for the X11 algorithm
 */
#include "hashblock.h"
#include <inttypes.h>

#include <jni.h>



jbyteArray JNICALL hash15_native(JNIEnv *env, jclass cls, jbyteArray header, jint offset, jint length)
{
    jint Plen = (env)->GetArrayLength(header);
    jbyte *P = (env)->GetByteArrayElements(header, NULL);
    jbyteArray DK = NULL;

    if (P && Plen >= offset + length)
	{
	
	uint256 result = HashSph(P+offset, P+offset+length);

    DK = (env)->NewByteArray(32);
    if (DK)
	{
		(env)->SetByteArrayRegion(DK, 0, 32, (jbyte *) result.begin());
	}
	

    if (P) (env)->ReleaseByteArrayElements(header, P, JNI_ABORT);
	}
    return DK;
}

static const JNINativeMethod methods[] = {
    { "x15_native", "([BII)[B", (void *) hash15_native }
};

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;

    if ((vm)->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    jclass cls = (env)->FindClass("com/hashengineering/crypto/X15");
    int r = (env)->RegisterNatives(cls, methods, 1);

    return (r == JNI_OK) ? JNI_VERSION_1_6 : -1;
}
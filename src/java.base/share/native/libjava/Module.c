/*
 * Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.  Oracle designates this
 * particular file as subject to the "Classpath" exception as provided
 * by Oracle in the LICENSE file that accompanied this code.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 */

#include "jni.h"
#include "jvm.h"

#include "java_lang_reflect_Module.h"

JNIEXPORT void JNICALL
Java_java_lang_reflect_Module_jvmDefineModule(JNIEnv *env, jclass cls, jclass module, jstring version,
                                              jstring location, jobjectArray packages)
{
    JVM_DefineModule(env, module, version, location, packages);
}

JNIEXPORT void JNICALL
Java_java_lang_reflect_Module_jvmAddModuleExports(JNIEnv *env, jclass cls, jobject from,
                                                  jstring pkg, jobject to)
{
    JVM_AddModuleExports(env, from, pkg, to);
}

JNIEXPORT void JNICALL
Java_java_lang_reflect_Module_jvmAddReadsModule(JNIEnv *env, jclass cls, jobject from, jobject to)
{
    JVM_AddReadsModule(env, from, to);
}

JNIEXPORT void JNICALL
Java_java_lang_reflect_Module_jvmAddModulePackage(JNIEnv *env, jclass cls, jobject m, jstring pkg)
{
    JVM_AddModulePackage(env, m, pkg);
}

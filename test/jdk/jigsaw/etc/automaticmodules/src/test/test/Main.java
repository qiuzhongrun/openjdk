/*
 * Copyright (c) 2015, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
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

package test;

import java.lang.module.*;
import java.lang.reflect.Module;

import http.HttpServer;

/**
 * Basic test using automatic modules.
 */

public class Main {
    public static void main(String[] args) throws Exception {

        Module httpModule = HttpServer.class.getModule();

        // automatic modules are named
        assertTrue(httpModule.isNamed());

        // and loose
        assertTrue(httpModule.canRead(null));

        // and read all modules in the boot Layer
        Layer layer = Layer.boot();
        layer.configuration().get().descriptors().stream()
                .map(ModuleDescriptor::name)
                .map(layer::findModule)
                .forEach(om -> assertTrue(httpModule.canRead(om.get())));

        // run code in the automatic modue, ensures access is allowed
        HttpServer http = new HttpServer(80);
        http.start();
    }

    static void assertTrue(boolean e) {
        if (!e)
            throw new RuntimeException();
    }
}

<?php

/*
 * Copyright (C) 2024 Cedrik Pischem
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

function ndproxy_services()
{
    global $config;

    $services = [];

    if (
        isset($config['OPNsense']['ndproxy']['general']['enabled']) &&
        $config['OPNsense']['ndproxy']['general']['enabled'] == 1
    ) {
        $services[] = [
            'description' => gettext('Ndproxy'),
            'configd' => [
                'start' => ['ndproxy start'],
                'restart' => ['ndproxy restart'],
                'stop' => ['ndproxy stop'],
            ],
            'name' => 'ndproxy',
            'nocheck' => true,
        ];
    }

    return $services;
}

function ndproxy_xmlrpc_sync()
{
    $result = [];

    $result[] = array(
        'description' => gettext('Ndproxy'),
        'section' => 'OPNsense.ndproxy',
        'id' => 'ndproxy',
        'services' => ["ndproxy"],
    );

    return $result;
}

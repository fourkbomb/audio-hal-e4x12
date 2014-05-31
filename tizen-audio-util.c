/*
 * audio-hal
 *
 * Copyright (c) 2000 - 2013 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Hyunseok Lee <hs7388.lee@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "tizen-audio-internal.h"

audio_return_t _audio_util_init (audio_mgr_t *am)
{
    pthread_mutex_init(&(am->mixer.mutex), NULL);
    return AUDIO_RET_OK;
}

audio_return_t _audio_util_deinit (audio_mgr_t *am)
{
    pthread_mutex_destroy(&(am->mixer.mutex));
    return AUDIO_RET_OK;
}

static void __dump_mixer_param(char *dump, long *param, int size)
{
    int i, len;

    for (i = 0; i < size; i++) {
        len = sprintf(dump, "%ld", *param);
        if (len > 0)
            dump += len;
        if (i != size -1) {
            *dump++ = ',';
        }

        param++;
    }
    *dump = '\0';
}

audio_return_t _audio_mixer_control_set_param(audio_mgr_t *am, const char* ctl_name, struct snd_ctl_elem_value* param, int size)
{
    audio_return_t ret = AUDIO_RET_USE_HW_CONTROL;
    char dump_str[AUDIO_DUMP_STR_LEN];

    pthread_mutex_lock(&(am->mixer.mutex));

    AUDIO_LOG_DEBUG("mixer_ctl_set_param %s=%s success", ctl_name, dump_str);

exit:
    pthread_mutex_unlock(&(am->mixer.mutex));

    return ret;
}

audio_return_t _audio_mixer_control_get_value(audio_mgr_t *am, const char *ctl_name, int *val)
{
    audio_return_t ret = AUDIO_RET_USE_HW_CONTROL;

    pthread_mutex_lock(&(am->mixer.mutex));

    AUDIO_LOG_DEBUG("mixer_ctl_get %s=%d success", ctl_name, *val);

exit:
    pthread_mutex_unlock(&(am->mixer.mutex));

    return ret;
}

audio_return_t _audio_mixer_control_set_value(audio_mgr_t *am, const char *ctl_name, int val)
{
    audio_return_t ret = AUDIO_RET_USE_HW_CONTROL;

    pthread_mutex_lock(&(am->mixer.mutex));

    AUDIO_LOG_DEBUG("set_mixer %s=%d success", ctl_name, val);

exit:
    pthread_mutex_unlock(&(am->mixer.mutex));

    return ret;
}

audio_return_t _audio_mixer_control_set_value_string(audio_mgr_t *am, const char* ctl_name, const char* value)
{
    audio_return_t ret = AUDIO_RET_USE_HW_CONTROL;

    pthread_mutex_lock(&(am->mixer.mutex));

    AUDIO_LOG_DEBUG("set_mixer %s=%s success", ctl_name, value);

exit:
    pthread_mutex_unlock(&(am->mixer.mutex));

    return ret;
}


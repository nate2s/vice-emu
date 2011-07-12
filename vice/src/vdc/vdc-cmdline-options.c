/*
 * vdc-cmdline-options.c - Command-line options for the MOS 8563 (VDC)
 * emulation.
 *
 * Written by
 *  Ettore Perazzoli <ettore@comm2000.it>
 *  Markus Brenner <markus@brenner.de>
 *  Andreas Boose <viceteam@t-online.de>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 * */

#include "vice.h"

#include <stdio.h>

#include "cmdline.h"
#include "raster-cmdline-options.h"
#include "resources.h"
#include "translate.h"
#include "vdc-cmdline-options.h"
#include "vdctypes.h"

/* VDC command-line options.  */
static const cmdline_option_t cmdline_options[] =
{
    { "-VDCstretchvertical", SET_RESOURCE, 0,
      NULL, NULL, "VDCStretchVertical", (resource_value_t)1,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_ENABLE_STRETCH_VERTICAL,
      NULL, NULL },
    { "+VDCstretchvertical", SET_RESOURCE, 0,
      NULL, NULL, "VDCStretchVertical", (resource_value_t)0,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_DISABLE_STRETCH_VERTICAL,
      NULL, NULL },
    { "-VDC16KB", SET_RESOURCE, 0,
      NULL, NULL, "VDC64KB", (resource_value_t)0,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_VDC_MEMORY_16KB,
      NULL, NULL },
    { "-VDC64KB", SET_RESOURCE, 0,
      NULL, NULL, "VDC64KB", (resource_value_t)1,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_VDC_MEMORY_64KB,
      NULL, NULL },
    { "-VDCRevision", SET_RESOURCE, 1,
      NULL, NULL, "VDCRevision", (resource_value_t)2,
      USE_PARAM_ID, USE_DESCRIPTION_ID,
      IDCLS_P_NUMBER, IDCLS_SET_VDC_REVISION,
      NULL, NULL },
    { "-saturation", SET_RESOURCE, 1,
      NULL, NULL, "ColorSaturation", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_SATURATION,
      "<0-2000>", NULL },
    { "-contrast", SET_RESOURCE, 1,
      NULL, NULL, "ColorContrast", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_CONTRAST,
      "<0-2000>", NULL },
    { "-brightness", SET_RESOURCE, 1,
      NULL, NULL, "ColorBrightness", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_BRIGHTNESS,
      "<0-2000>", NULL },
    { "-gamma", SET_RESOURCE, 1,
      NULL, NULL, "ColorGamma", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_GAMMA,
      "<0-4000>", NULL },
    { "-tint", SET_RESOURCE, 1,
      NULL, NULL, "ColorTint", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_TINT,
      "<0-2000>", NULL },
/*
    { "-oddlinesphase", SET_RESOURCE, 1,
      NULL, NULL, "PALOddLinePhase", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_ODDLINES_PHASE,
      "<0-2000>", NULL },
    { "-oddlinesoffset", SET_RESOURCE, 1,
      NULL, NULL, "PALOddLineOffset", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_ODDLINES_OFFSET,
      "<0-2000>", NULL },
*/
    { "-crtblur", SET_RESOURCE, 1,
      NULL, NULL, "PALBlur", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_BLUR,
      "<0-1000>", NULL },
    { "-crtscanlineshade", SET_RESOURCE, 1,
      NULL, NULL, "PALScanLineShade", NULL,
      USE_PARAM_STRING, USE_DESCRIPTION_ID,
      IDCLS_UNUSED, IDCLS_SET_SCANLINE_SHADE,
      "<0-1000>", NULL },
    { NULL, 0, 0,
      NULL, NULL, NULL, NULL,
      0, 0,
      0, 0,
      NULL, NULL }
};

int vdc_cmdline_options_init(void)
{
    if (raster_cmdline_options_chip_init("VDC", vdc.video_chip_cap) < 0) {
        return -1;
    }

    return cmdline_register_options(cmdline_options);
}

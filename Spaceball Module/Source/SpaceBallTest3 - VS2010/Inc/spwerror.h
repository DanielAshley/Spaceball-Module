/*----------------------------------------------------------------------
 *  spwerror.h -- Standard 3Dconnexion function return values
 *
 *  This file contains all the 3Dconnexion standard error return
 *  return values for functions
 *
 *----------------------------------------------------------------------
 *
 * (C) 1998-2012 3Dconnexion. All rights reserved. 
 * Permission to use, copy, modify, and distribute this software for all
 * purposes and without fees is hereby grated provided that this copyright
 * notice appears in all copies.  Permission to modify this software is granted
 * and 3Dconnexion will support such modifications only is said modifications are
 * approved by 3Dconnexion.
 *
 */

#ifndef _SPWERROR_H_
#define _SPWERROR_H_

static char spwerrorCvsId[]="(C) 1996-2012 3Dconnexion: $Id: spwerror.h 7481 2012-02-06 23:40:55Z jim_wick $";

enum SpwRetVal             /* Error return values.                           */
   {
   SPW_NO_ERROR,           /* No error.                                      */
   SPW_ERROR,              /* Error -- function failed.                      */
   SI_BAD_HANDLE,          /* Invalid SpaceWare handle.                      */
   SI_BAD_ID,              /* Invalid device ID.                             */
   SI_BAD_VALUE,           /* Invalid argument value.                        */
   SI_IS_EVENT,            /* Event is a SpaceWare event.                    */
   SI_SKIP_EVENT,          /* Skip this SpaceWare event.                     */
   SI_NOT_EVENT,           /* Event is not a SpaceWare event.                */
   SI_NO_DRIVER,           /* SpaceWare driver is not running.               */
   SI_NO_RESPONSE,         /* SpaceWare driver is not responding.            */
   SI_UNSUPPORTED,         /* The function is unsupported by this version.   */
   SI_UNINITIALIZED,       /* SpaceWare input library is uninitialized.      */
   SI_WRONG_DRIVER,        /* Driver is incorrect for this SpaceWare version.*/
   SI_INTERNAL_ERROR,      /* Internal SpaceWare error.                      */
   SI_BAD_PROTOCOL,        /* The transport protocol is unknown.             */
   SI_OUT_OF_MEMORY,       /* Unable to malloc space required.               */
   SPW_DLL_LOAD_ERROR,     /* Could not load siapp dlls                      */
   SI_NOT_OPEN,            /* Spaceball device not open                      */
   SI_ITEM_NOT_FOUND,	   /* Item not found                                 */
   SI_UNSUPPORTED_DEVICE,  /* The device is not supported                    */
   SI_NOT_ENOUGH_MEMORY,   /* Not enough memory (but not a malloc problem)   */
   SI_SYNC_WRONG_HASHCODE,  /* Wrong hash code sent to a Sync function        */
   SI_INCOMPATIBLE_PROTOCOL_MIX  /* Attempt to mix MWM and S80 protocol in invalid way */
   };

typedef enum SpwRetVal SpwReturnValue;

#endif   /* _SPWERROR_H_ */

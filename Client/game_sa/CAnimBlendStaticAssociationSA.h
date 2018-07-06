/*****************************************************************************
 *
 *  PROJECT:     Multi Theft Auto v1.0
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        game_sa/CAnimBlendStaticAssociationSA.h
 *  PURPOSE:     Header file for animation blend static association class
 *
 *  Multi Theft Auto is available from http://www.multitheftauto.com/
 *
 *****************************************************************************/

/* CAnimBlendStaticAssociation: 1 per uncompressed animation?*/

#ifndef __CAnimBlendStaticAssociationSA_H
#define __CAnimBlendStaticAssociationSA_H

#include <game/CAnimBlendStaticAssociation.h>
#include "Common.h"

#define FUNC_CAnimBlendStaticAssociation_Initialize 0x4CEC20

class CAnimBlendAssocGroupSA;
class CAnimBlendHierarchySAInterface;
class CAnimBlendHierarchy;

class CAnimBlendStaticAssociationSAInterface
{
protected:
    void* vTable;

public:
    unsigned short                  nNumBlendNodes;
    short                           sAnimID;
    short                           sAnimGroup;
    short                           sFlags;
    int*                            pAnimBlendNodesSequenceArray;
    CAnimBlendHierarchySAInterface* pAnimHeirarchy;
};

class CAnimBlendStaticAssociationSA : public CAnimBlendStaticAssociation
{
public:
    CAnimBlendStaticAssociationSA(CAnimBlendStaticAssociationSAInterface* pInterface) { m_pInterface = pInterface; }
    void Initialize(RpClump* pClump, CAnimBlendHierarchySAInterface* pAnimBlendHierarchyInterface);
    void SetNumBlendNodes(unsigned short nNumBlendNodes) { m_pInterface->nNumBlendNodes = nNumBlendNodes; };
    void SetAnimID(short sAnimID) { m_pInterface->sAnimID = sAnimID; }
    void SetAnimGroup(short sAnimGroup) { m_pInterface->sAnimGroup = sAnimGroup; }
    void SetFlags(short sFlags) { m_pInterface->sFlags = sFlags; }

    unsigned short                  GetNumBlendNodes(void) { return m_pInterface->nNumBlendNodes; };
    short                           GetAnimID(void) { return m_pInterface->sAnimID; }
    short                           GetAnimGroup(void) { return m_pInterface->sAnimGroup; }
    short                           GetFlags(void) { return m_pInterface->sFlags; }
    CAnimBlendHierarchySAInterface* GetAnimHierachyInterface(void) { return m_pInterface->pAnimHeirarchy; }

protected:
    CAnimBlendStaticAssociationSAInterface* m_pInterface;
};

#endif

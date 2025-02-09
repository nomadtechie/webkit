/*
 * Copyright (C) 2015 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#pragma once

#include "HTMLElement.h"
#include "MediaQueryEvaluator.h"

namespace WebCore {

class HTMLPictureElement final : public HTMLElement {
    WTF_MAKE_ISO_ALLOCATED(HTMLPictureElement);
public:
    static Ref<HTMLPictureElement> create(const QualifiedName&, Document&);
    virtual ~HTMLPictureElement();

    void sourcesChanged();

    void clearViewportDependentResults() { m_viewportDependentMediaQueryResults.clear(); }
    bool hasViewportDependentResults() const { return m_viewportDependentMediaQueryResults.size(); }
    Vector<MediaQueryResult>& viewportDependentResults() { return m_viewportDependentMediaQueryResults; }

    bool viewportChangeAffectedPicture() const;

    WeakPtr<HTMLPictureElement> createWeakPtr() { return m_weakFactory.createWeakPtr(*this); }

#if USE(SYSTEM_PREVIEW)
    WEBCORE_EXPORT bool isSystemPreviewImage() const;
#endif

private:
    HTMLPictureElement(const QualifiedName&, Document&);

    void didMoveToNewDocument(Document& oldDocument, Document& newDocument) final;

    WeakPtrFactory<HTMLPictureElement> m_weakFactory;
    Vector<MediaQueryResult> m_viewportDependentMediaQueryResults;
};

} // namespace WebCore

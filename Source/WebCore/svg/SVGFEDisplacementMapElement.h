/*
 * Copyright (C) 2006 Oliver Hunt <oliver@nerget.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#pragma once

#include "FEDisplacementMap.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedNumber.h"
#include "SVGFilterPrimitiveStandardAttributes.h"

namespace WebCore {
 
template<>
struct SVGPropertyTraits<ChannelSelectorType> {
    static unsigned highestEnumValue() { return CHANNEL_A; }

    static String toString(ChannelSelectorType type)
    {
        switch (type) {
        case CHANNEL_UNKNOWN:
            return emptyString();
        case CHANNEL_R:
            return ASCIILiteral("R");
        case CHANNEL_G:
            return ASCIILiteral("G");
        case CHANNEL_B:
            return ASCIILiteral("B");
        case CHANNEL_A:
            return ASCIILiteral("A");
        }

        ASSERT_NOT_REACHED();
        return emptyString();
    }

    static ChannelSelectorType fromString(const String& value)
    {
        if (value == "R")
            return CHANNEL_R;
        if (value == "G")
            return CHANNEL_G;
        if (value == "B")
            return CHANNEL_B;
        if (value == "A")
            return CHANNEL_A;
        return CHANNEL_UNKNOWN;
    }
};

class SVGFEDisplacementMapElement final : public SVGFilterPrimitiveStandardAttributes {
    WTF_MAKE_ISO_ALLOCATED(SVGFEDisplacementMapElement);
public:
    static Ref<SVGFEDisplacementMapElement> create(const QualifiedName&, Document&);

    static ChannelSelectorType stringToChannel(const String&);
    
private:
    SVGFEDisplacementMapElement(const QualifiedName& tagName, Document&);
    
    void parseAttribute(const QualifiedName&, const AtomicString&) override;
    bool setFilterEffectAttribute(FilterEffect*, const QualifiedName& attrName) override;
    void svgAttributeChanged(const QualifiedName&) override;
    RefPtr<FilterEffect> build(SVGFilterBuilder*, Filter&) override;

    BEGIN_DECLARE_ANIMATED_PROPERTIES(SVGFEDisplacementMapElement)
        DECLARE_ANIMATED_STRING(In1, in1)
        DECLARE_ANIMATED_STRING(In2, in2)
        DECLARE_ANIMATED_ENUMERATION(XChannelSelector, xChannelSelector, ChannelSelectorType)
        DECLARE_ANIMATED_ENUMERATION(YChannelSelector, yChannelSelector, ChannelSelectorType)
        DECLARE_ANIMATED_NUMBER(Scale, scale)
    END_DECLARE_ANIMATED_PROPERTIES
};

} // namespace WebCore

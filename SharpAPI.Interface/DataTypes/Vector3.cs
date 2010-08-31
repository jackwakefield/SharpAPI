/*
 *  This file is a part of SharpAPI.
 *
 *  Copyright (C) 2010 Jack Wakefield
 *  
 *  SharpAPI is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SharpAPI is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with SharpAPI.  If not, see <http://www.gnu.org/licenses/>.
 */

/// <summary>
/// Defines a vector with three components.
/// </summary>
struct Vector3
{
    #region Constructor

    /// <summary>
    /// Initializes a new instance of the <see cref="Vector3"/> struct.
    /// </summary>
    /// <param name="x">The x.</param>
    /// <param name="y">The y.</param>
    /// <param name="z">The z.</param>
    public Vector3(float x, float y, float z = 0.0f)
    {
        X = x;
        Y = y;
        Z = z;
    }

    #endregion

    public float X;
    public float Y;
    public float Z;
};